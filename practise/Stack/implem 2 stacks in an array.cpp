// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

class twoStacks
{
    // public:
    int size;
    int top1;
    int top2;
    int *arr;
    
    public:
    
    // default parameter is necessary for constructors
    twoStacks(int n = 100)
    {
        this -> size = n;
        top1 = -1;
        top2 = n;
        arr = new int[n];
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = x;
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1 >= 0){
            top1--;
            return arr[top1+1];
        }else{
            return -1;
        }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2 < size){
            top2++;
            return arr[top2-1];
        }else{
            return -1;
        }
    }
};
