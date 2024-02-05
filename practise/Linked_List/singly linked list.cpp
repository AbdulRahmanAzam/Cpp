#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;

        // free memory
        if(this -> next == NULL){
            delete next;
            this -> next = NULL;    
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int n){
    //create new node
    Node* temp = new Node(n);

    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int n){
    //create new node
    Node* temp = new Node(n);

    tail -> next = temp;
    tail = tail -> next;
}

void insertAtpos(Node* &head, Node* &tail, int pos, int n){
    // if it is at first position
    if(pos == 1){
        insertAtHead(head, n);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp -> next;
        cnt++;
    }

    // if it is at last
    if(temp -> next == NULL){
        insertAtTail(tail, n);
        return;
    }

    // create new node
    Node* nodeToInsert = new Node(n);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        // free memory form start node
        delete temp;
    }else{
        //free memory from mid or last
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr  -> next;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    //created a new node
    Node* node1 = new Node(10);
    
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node* head = node1 ;
    Node* tail = node1;

    print(head);

    // inserting at head
    // insertAtHead(head, 12);
    // insertAtHead(head, 14);
    
    insertAtTail(tail, 12);
    insertAtTail(tail, 14);

    insertAtpos(head, tail, 1, 20);
    insertAtpos(head, tail, 2, 30);
    insertAtpos(head, tail, 5, 40);

    print(head);

    deleteNode(head, 5);

    print(head);
}
