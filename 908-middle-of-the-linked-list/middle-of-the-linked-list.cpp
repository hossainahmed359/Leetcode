
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        for (ListNode* i = head; i != NULL; i = i->next) {
            len++;
        }

        ListNode* curr = head;
        for (int i = 0; i < len / 2; i++) {
            curr = curr->next;
        }

        return curr;
    }
};