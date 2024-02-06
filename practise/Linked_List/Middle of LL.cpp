/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int toGetLength(Node* head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        temp = temp -> next;
        len++;
    }

    return len;
}

Node *findMiddle(Node *head) {
    int len = toGetLength(head);
    len /= 2;

    Node* temp = head;

    int a = 0;

    while(a < len){
        temp = temp -> next;
        a++;
    }
    return temp;
}
// // this is also another method with higher efficiency without finding length
// Node *findMiddle(Node *head) {
// // for 1  node
    // if(head == NULL || head -> next == NULL){
    //     return head;
    // }

    // // for 2 node
    // if(head -> next -> next == NULL){
    //     return head -> next;
    // }

    // Node* slow = head;
    // Node* fast = head;

    // while(fast -> next != NULL){

    //     fast = fast -> next;

    //     if (fast -> next != NULL) 
    //         fast = fast->next;

    //     slow = slow->next;
    // }
    // return slow;
// }

