#include <iostream>
#include <stack>
using namespace std;

class Stack {
    public:
    int size;
    int top;
    int *arr;
    
    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void pop(){
        if(top >= 0){
            cout << "Popped element is = " << arr[top] << endl;
            top--;
        }else{
            cout << "stack underflow" << endl;
        }
    }
    
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }else{
            cout << "stack overflow" << endl;
        }
    }
    
    bool isempty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
    int peek(){
        if(top >= 0){
            return arr[top];
        }else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
};

int main(){
    // stack declaration
    // stack<int> s;
    Stack s(5);

    // push elements into stack
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "the first or top element is = " << s.peek() << endl;
    
    // deleting first element from a stack
    s.pop();
    s.pop();

    cout << "the first or top element is = " << s.peek() << endl;

    if(s.isempty()){
        cout << "stack is empty" << endl;
    }else{
        cout << "stack is not empty" << endl;
    }


}
