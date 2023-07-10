class Solution {
public:
    
    int ans(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i>=0 && j>=0 && grid[i][j]==1)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up= ans(grid,i-1,j,dp);
        int left = ans(grid,i,j-1,dp);
        return dp[i][j]= up+left;
    
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return ans(obstacleGrid,n-1,m-1,dp);
    }
};