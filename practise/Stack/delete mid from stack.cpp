// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

void solve(stack<int>&s, int size, int count){
        // base case of middle count
        if(count == size / 2){
            s.pop();
            return;
        }
        
        // having top element
        int elem = s.top();
        
        // pop it for the recursion
        s.pop();
        
        // recursive call
        solve(s, size, count+1);
        
        // when base case occured push all the values one by one
        s.push(elem);
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        solve(s, sizeOfStack, count);
    }
