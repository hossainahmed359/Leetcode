class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stA, stB;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '#' && !stA.empty()) {
                stA.pop();
            } else if (ch != '#') {
                stA.push(ch);
            }
        }

        for (int i = 0; i < t.size(); i++) {
            char ch = t[i];
            if (ch == '#' && !stB.empty()) {
                stB.pop();
            } else if (ch != '#') {
                stB.push(ch);
            }
        }

        return stA == stB;
    };
};