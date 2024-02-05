#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        
        if(this -> next == NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int n){
    Node* newNode = new Node(n);
    
    //empty list
    if(tail == NULL){
        tail = newNode;
        newNode -> next = newNode;
    }else{
        // non- empty list
        // assuming that elemnt is present in the list
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        newNode -> next = curr -> next;
        curr -> next = newNode; 
    }
}

void deleteNode(Node* &tail, int n){

    if(tail == NULL){
        cout << "Node is empty, please check again" << endl;
        return;
    }else{ 
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != n){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        // more than 1 Node linked list
        if(curr == prev){
            tail = NULL;
        }
        // 1 Node linked list
        else if(tail == curr){
            tail = prev;
        }else{
            curr -> next = NULL;
        }
        delete curr;
    }
} 

void print(Node* &tail){
    // empty list
    if(tail == NULL){
        cout << "List in empty" << endl;
        return;
    }

    Node* temp = tail;

    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != tail);
    cout << endl;
}

int main(){
    Node* tail = NULL;
    // print(tail);

    insertNode(tail, 6, 3);
    print(tail);

    // insertNode(tail, 3, 9);
    // print(tail);

    // insertNode(tail, 9, 1);
    // print(tail);

    // insertNode(tail, 3, 2);
    // print(tail);

    // insertNode(tail, 2, 7);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);
}
