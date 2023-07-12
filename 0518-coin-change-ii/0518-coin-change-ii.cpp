class Solution {
public:
    
    int ans(vector<int>& coins,int idx,int target,vector<vector<int>>&dp){
        if(idx==0){
            return (target%coins[0]==0);
              
        }
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        
        int notaken = ans(coins,idx-1,target,dp);
        int take=0;
        if(coins[idx]<=target)
            take = ans(coins,idx,target-coins[idx],dp);
        return dp[idx][target]= take+notaken;
    }
    
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return ans(coins,n-1,amount,dp);
    }
};