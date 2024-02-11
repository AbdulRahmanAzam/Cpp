https://www.geeksforgeeks.org/problems/reverse-a-string-using-stack/1?

char* reverse(char *S, int len)
{
    stack<char> st;
    
    for(int i=0; i< len; i++){
        char ch = S[i];
        st.push(ch);
    }
    
    
    char* ans = new char[len+1];
    
    for(int j=0; j< len; j++){
        char ch = st.top();
        ans[j] = ch;
        st.pop();
    }
    
    
    return ans;
}
