// https://leetcode.com/problems/maximal-rectangle/

// this is taken from histogram question
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
                ans = max(ans, h * len);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        // convert character to integer
        vector<vector<int>> intmatrix(row, vector<int>(col, 0));
        for(int i=0; i< row; i++){
            for(int j=0; j< col; j++){
                intmatrix[i][j] = matrix[i][j] - '0';
            }
        }
        // area of first row
        int area = largestRectangleArea(intmatrix[0]);
        for(int i=1; i< row; i++){
            for(int j=0; j< col ;j++){
                // row update: by adding previous rows value
                if(intmatrix[i][j] != 0){
                    intmatrix[i][j] = intmatrix[i][j] + intmatrix[i-1][j];
                }else{
                    intmatrix[i][j] =0;
                }

            }
            // entire row is updated now
            area = max(area, largestRectangleArea(intmatrix[i]));
        }
        return area;
    }
