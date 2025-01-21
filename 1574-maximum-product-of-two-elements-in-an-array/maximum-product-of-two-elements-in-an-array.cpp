class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = 0;

        int len = nums.size();

        for (int i = 0; i < len - 1; i++) {
            for (int j = 1; j < len; j++) {
                int currVal = ((nums[i] - 1) * (nums[j] - 1));
                if (currVal > maxVal && i != j)
                    maxVal = currVal;
            }
        }

        return maxVal;
    }
};