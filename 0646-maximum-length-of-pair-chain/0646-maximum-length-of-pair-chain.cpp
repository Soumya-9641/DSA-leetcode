class Solution {
public:
    
    int ans(int i,int prev,vector<vector<int>>& pairs,int n,vector<vector<int>>&dp){
        if(i==n)
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int pick=INT_MIN;
        if(prev==-1||pairs[prev][1]<pairs[i][0])
            pick=1+ans(i+1,i,pairs,n,dp);
        int notpick=ans(i+1,prev,pairs,n,dp);
        
        return dp[i][prev+1]= max(pick,notpick);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n= pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return ans(0,-1,pairs,n,dp);
    }
};