#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> prev = NULL;
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;

        // free memory 
        if(this -> next == NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
    cout << "head = " << head.data << endl << endl;
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int n){
    Node* temp = new Node(n);

    if(head == NULL){
        head = temp;
        tail = temp; 
    }else{
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    } 
}

void insertAtTail(Node* &head, Node* &tail, int n){
    Node* temp = new Node(n);

    if(tail == NULL){
        head = temp;
        tail = temp;
    }else{
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPos(Node* &head, Node* &tail, int pos, int n){
    Node* temp = head;
    // insert at first position
    if(pos == 1){
        insertAtHead(head, tail, n);
        return;
    }

    int cnt = 1;
    while(cnt < pos - 1){
        temp = temp -> next;
        cnt++;
    }

    // insert at last position
    if(temp -> next == NULL){
        insertAtTail(head, tail, n);
        return;
    }

    Node* nodeToInsert = new Node(n);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(Node* &head, int pos){
    Node* temp = head;
    //delete first of start node;   
    if(pos == 1){
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
   // // Node* node1 = new Node(5);

    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    
    cout << "length = " << getLength(head) << endl;

    insertAtHead(head, tail, 6);
    
    print(head, tail);
    cout << "length = " << getLength(head) << endl;

    insertAtTail(head, tail, 10);
    print(head);

    insertAtPos(head, tail, 2, 50);
    print(head);
    
    insertAtPos(head, tail, 1, 33);
    print(head);
    
    insertAtPos(head, tail, 5, 66);
    print(head);
}
