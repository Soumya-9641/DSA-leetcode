class Solution {
public:
    
    int ans(vector<vector<int>>& triangle,int row,int col,int n,vector<vector<int>>&dp){
         
        if(row==n-1)
            return triangle[n-1][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        
        int down =triangle[row][col] +ans(triangle,row+1,col,n,dp);
        int diag = triangle[row][col] +ans(triangle,row+1,col+1,n,dp);
        return dp[row][col]= min(down ,diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
      int n =triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return ans(triangle,0,0,n,dp); 
    }
};