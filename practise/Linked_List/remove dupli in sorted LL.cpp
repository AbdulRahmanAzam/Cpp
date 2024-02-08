//remove 100% duplicate means
// in: {1,2,2,3,3,4}
// out: {1,4}

ListNode* deleteDuplicates(ListNode* head) {
        //empty list
        if(head == NULL)
            return NULL;

        ListNode* dummy = new ListNode(0, head);

        ListNode* prev = dummy;

        while(head != NULL){
            if(head -> next != NULL && head -> val == head -> next -> val){
                while(head -> next != NULL && head -> val == head -> next -> val){
                    head = head -> next;
                }
                prev -> next = head -> next;
                
            }else{
                prev = prev -> next;
            }
            head = head -> next;
        }

        return dummy -> next;
}

// it is not 100%
ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode* curr = head;

        while(curr != NULL){
            if(curr -> next != NULL && curr -> val == curr -> next -> val){
                curr -> next = curr -> next -> next;
            }else{
                curr = curr -> next;
            }
        }
        return head;
    }





