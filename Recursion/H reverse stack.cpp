// https://www.geeksforgeeks.org/problems/reverse-a-stack/1?

void insertAtBottom(stack<int> &s, int x){
        if(s.empty()){
            s.push(x);
            return;
        }
        
        int top = s.top();
        s.pop();
        
        insertAtBottom(s, x);
        
        s.push(top);
    }
    
    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        
        int top = St.top();
        St.pop();
        
        Reverse(St);
        
        insertAtBottom(St, top);
    }
