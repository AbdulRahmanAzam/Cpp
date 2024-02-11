// same question as delete element from middle of stack
    void solve(stack<int>& s, int x, int n , int count = 0){
        // base case as stack counts becomes equal to its size
        if(count == n){
            s.push(x);
            return;
        }
        
        int top = s.top();
        s.pop();
        
        solve(s, x, n, count + 1);
        
        s.push(top);
    }
    
    stack<int> insertAtBottom(stack<int> st,int x){
        solve(st, x, st.size());
        return st;
    }
