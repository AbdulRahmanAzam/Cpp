// this is done using two method, stacks and map

// bool isValid(string s) {
    //     stack<char> stack;

    //     for(int i=0; i< s.size(); i++){
    //         char ch = s[i];

    //         if(ch == '(' || ch == '[' || ch == '{'){
    //             stack.push(ch);
    //         }else{
    //             if(!stack.empty()){
    //                 int top = stack.top();

    //                 if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
    //                     stack.pop();
    //                 }else{
    //                     return false;
    //                 }
    //             }else{
    //                 return false;
    //             }
    //         }
    //     }
    //     // if(stack.empty()){
    //     //     return true;
    //     // }else{
    //     //     return false;
    //     // }
    //     return stack.empty();
    // }

    bool isValid(string s){
        stack <char> st;
        map<char, char> M;
        M['}'] = '{';
        M[']'] = '[';
        M[')'] = '(';

        // having no braces before and after loop speeds run time
        for(int i =0; i< s.size(); i++)
            if(st.empty())
                st.push(s[i]);
            else if(st.top() == M[s[i]])
                st.pop();
            else
                st.push(s[i]);
        
        return st.empty();
    }
