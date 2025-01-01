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
        ListNode* start = getNodeAtIndex(list1, a - 1);
        ListNode* end = getNodeAtIndex(list1, b);
        ListNode* listTwoTail = getNodeAtTail(list2);

        start->next = list2;
        listTwoTail->next = end->next;

        return list1;
    }
};