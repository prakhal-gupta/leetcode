class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        int n = heights.size();
        vector<int> left(n), right(n);
        stack <int> st1,st2;
        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i])
                st1.pop();
            if(st1.empty())
                left[i]=i+1;
            else
                left[i]=i-st1.top();
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i])
                st2.pop();
            if(st2.empty())
                right[i]=n-i;
            else
                right[i]=st2.top()-i;
            st2.push(i);
        }
        for(int i=0;i<n;i++){
            int w = left[i] + right[i] - 1;
            int area = heights[i]*w;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0)
                    mat[i][j] = matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='1')
                        mat[i][j] = mat[i-1][j] +1;
                }
            }
        }
        int result=0;
        for(int i=0;i<n;i++)
            result =  max(result, largestRectangleArea(mat[i]));
        return result;
    }
};
