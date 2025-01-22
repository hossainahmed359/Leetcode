class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *mergedHead = new ListNode(0);

        ListNode *curr = head;
        ListNode *currMerged = mergedHead;

        while(curr != NULL) {
            if(curr->val == 0) {
                curr = curr->next ? curr->next : NULL;
                if(curr == NULL) {
                    break;
                }
                ListNode *tmp = new ListNode(curr->val);
                currMerged->next = tmp;
                currMerged = tmp;
            } else {
                currMerged->val += curr->val; 
            }

            curr = curr->next;
        }

        ListNode *tmp = mergedHead;
        mergedHead = mergedHead->next;
        delete tmp;
        return mergedHead;

    }
};