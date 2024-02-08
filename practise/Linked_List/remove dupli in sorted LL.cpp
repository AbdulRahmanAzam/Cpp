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
