// USING SLOW FAST
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};



// USING FOR LOOP
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int len = 0;
//         for (ListNode* i = head; i != NULL; i = i->next) {
//             len++;
//         }

//         ListNode* curr = head;
//         for (int i = 0; i < len / 2; i++) {
//             curr = curr->next;
//         }

//         return curr;
//     }
// };
