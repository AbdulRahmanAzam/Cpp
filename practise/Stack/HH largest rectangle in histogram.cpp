// BRUTE FORCE APPROACH
    // int largestRectangleArea(vector<int>& heights) {
    //     int ans = 0, n = heights.size();

    //     for(int i=0;i < n;i++){
    //         int minh = INT_MAX;
    //         for(int j=i ; j< n ; j++){
    //             minh = min(heights[j], minh);
    //             int len = j - i + 1;
    //             ans = max(ans, len * minh);
    //         }
    //     }
    //     return ans;
    // }

// STACK APPROACH
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        stack<int> st;
        heights.push_back(0);

        for(int i = 0; i <= n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int top = st.top();
                int h = heights[top];
                st.pop();

                int len = st.empty() ? i : i - st.top() - 1;
                // if(st.empty()){
                //     len = i;
                // }else{
                //     int len = i - st.top() - 1;
                // }
                ans = max(ans, h * len);
            }
            st.push(i);
        }
        return ans;
    }
