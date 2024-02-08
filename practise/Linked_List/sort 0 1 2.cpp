// ################################################# BELOW METHID IS FIRST TOTAL COUNT THEN IMPLEMENT BY YOUR OWN
// Node* sortList(Node *head){
//     Node* temp = head;

//     int cnt0 = 0;
//     int cnt1 = 0;
//     int cnt2 = 0;

//     while(temp != NULL){
//         if(temp -> data == 0){
//             cnt0++;
//         }else if(temp -> data == 1){
//             cnt1++;
//         }else{
//             cnt2++;
//         }

//         temp = temp -> next;
//     }

//     temp = head;

//     while(temp != NULL){
//         if(cnt0 != 0){
//             temp -> data = 0;
//             cnt0--;
//         }else if(cnt1 != 0){
//             temp -> data = 1;
//             cnt1--;
//         }else if(cnt2 != 0){
//             temp -> data = 2;
//             cnt2--;
//         }else{
//             break;
//         }
//         temp = temp -> next;
//     }
//     return head;
// }
// #########################################################  BELOW METHOD IS MAKING LINKS TO THE NODES OR THE MAIN HEAD
void insertAtTail(Node* &tail, Node* temp){
    tail -> next = temp;
    tail = temp;
}

Node *sortList(Node *head) {
    Node* head_0 = new Node(-1);
    Node* tail_0 = head_0;

    Node* head_1 = new Node(-1);
    Node* tail_1 = head_1;

    Node* head_2 = new Node(-1);
    Node* tail_2 = head_2;

    Node* temp = head;

    while(temp != NULL){
        int val = temp -> data;

        if(val == 0){
            insertAtTail(tail_0, temp);
        }else if(val == 1){
            insertAtTail(tail_1, temp);
        }else if(val == 2){
            insertAtTail(tail_2, temp);
        }

        temp = temp -> next;
    }
  
    // merge 3 list
    if(head_1 != NULL)
        tail_0 -> next = head_1 -> next;
    else
        tail_0 -> next = head_2 -> next;

    tail_1 -> next = head_2 -> next;
    tail_2 -> next = NULL;

    head = head_0 -> next;

    delete head_0;
    delete head_1;
    delete head_2;

    return head;
}
