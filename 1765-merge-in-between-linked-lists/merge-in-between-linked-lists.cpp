/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode* getNodeAtIndex(ListNode* head, int index) {
        ListNode* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr;
    }

    ListNode* getNodeAtTail(ListNode* head) {
        ListNode* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        return curr;
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* NodePrevA = getNodeAtIndex(list1, a - 1);
        ListNode* NodeB = getNodeAtIndex(list1, b);
        ListNode* List2TailNode = getNodeAtTail(list2);

        NodePrevA->next = list2;
        List2TailNode->next = NodeB->next;

        return list1;
    }
};