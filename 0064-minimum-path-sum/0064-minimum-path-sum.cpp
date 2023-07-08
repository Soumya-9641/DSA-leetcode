class Solution {
public:
    
    int ans(vector<vector<int>>& grid,int row,int col,vector<vector<int>>dp){
        if(row==0 && col==0){
            return grid[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int m = INT_MAX;
        int s;
        if(col>0){
             m = grid[row][col]+ans(grid,row,col-1,dp);
        }
        if(row>0){
            s = grid[row][col]+ ans(grid,row-1,col,dp);
            m=min(m,s);
        }
        
         dp[row][col]=m;
        return dp[row][col];
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        // int row = grid.size()-1;
        // int col = grid[0].size()-1;
        // vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        // return ans(grid,row,col,dp);
        
        
        //tabulation method
        int r = grid.size();
        int c= grid[0].size();
        
        vector<vector<int>>dp(r,vector<int>(c,0));
        dp[0][0]=grid[0][0];
        for(int i =1;i<c;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
         for(int i =1;i<r;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int i =1;i<r;i++){
            for(int j=1;j<c;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[r-1][c-1];
    }
};