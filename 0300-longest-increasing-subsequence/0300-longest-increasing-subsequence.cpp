class Solution {
public:
    
    int sol(vector<int>& nums,int idx,int prev,vector<vector<int>>&dp,int n){
        
       // int n = nums.size();
        if(idx==n)
            return 0;
        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];
        int len = 0+sol(nums,idx+1,prev,dp,n);
        if(prev==-1 || nums[idx]> nums[prev]){
             len =max(len, 1+sol(nums,idx+1,idx,dp,n)); 
        }
       return dp[idx][prev+1]= len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return sol(nums,0,-1,dp,n);
        
    }
};