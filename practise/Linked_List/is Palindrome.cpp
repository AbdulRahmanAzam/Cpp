// ##################################### traverse list putting elemnts in stack then check and pop stack
// bool isPalindrome(ListNode* &head) {
    //     ListNode* temp = head;

    //     stack<int> s;
    //     while(temp != NULL){
    //         s.push(temp -> val);
    //         temp = temp -> next;
    //     }

    //     while(head != NULL){
    //         int i = s.top();

    //         s.pop();

    //         if(head -> val != i){
    //             return false;
    //         }

    //         head = head -> next;
    //     }

    //     return true;
    // }


//############################################ here first find the middle then reverse it then check (middle to first and middle to last)
    ListNode* getMiddle(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* &head){
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL)
            return true;

        //step1 find middle
        ListNode* middle = getMiddle(head);

        //step2 reverse list after middle
        ListNode* temp = middle -> next;
        middle -> next = reverseList(temp);

        //step3 compare both  halves
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;

        while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }

            head1 = head1 -> next;
            head2 = head2 -> next;
        }

        // step4 repeat step2 to have the same head as before
        temp = middle -> next;
        middle -> next = reverseList(temp);

        return temp;
    }
