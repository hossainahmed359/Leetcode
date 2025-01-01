class Solution {

int get_len(ListNode *head) {
    int len = 0;

    ListNode *tmp = head;
    while(tmp != NULL) {
        len++;
        tmp = tmp->next;
    }

    return len;
}

void insert_at_tail(ListNode *&head, int val) {

    ListNode *tmp = new ListNode();
    tmp->val = val;
    tmp->next = NULL;

    if(head == NULL) {
        head = tmp;
        return;
    }

    ListNode *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = tmp;

}
  

public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead = NULL;
        ListNode *evenHead = NULL;
        ListNode *mergedHead = NULL;

        int len = get_len(head);

        ListNode *curr = head;

        for(int i = 1; i <= len; i++) {
            if(i%2 != 0) {
                insert_at_tail(oddHead, curr->val);
            } else {
                insert_at_tail(evenHead, curr->val);
            }
            curr = curr->next;
        }

        ListNode *currOdd = oddHead;
        while(currOdd != NULL) {
            insert_at_tail(mergedHead, currOdd->val);
            currOdd = currOdd->next;
        }

        ListNode *currEven = evenHead;
        while(currEven != NULL) {
            insert_at_tail(mergedHead, currEven->val);
            currEven = currEven->next;
        }

        return mergedHead;
    }
};