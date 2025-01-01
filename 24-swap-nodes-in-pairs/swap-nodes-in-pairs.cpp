class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(curr->next != NULL) swap(curr->val , curr->next->val);
            curr = curr->next->next ? curr->next->next : NULL;
        }

        return head;
    }
};