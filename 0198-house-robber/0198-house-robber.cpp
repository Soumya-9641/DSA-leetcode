class Solution {
public:
    
    // int solve(vector<int>& nums,int n){
    //     if(n<0)
    //         return 0;
    //     if(n==0)
    //         return nums[0];
    //     int incl = solve(nums,n-2)+nums[n];
    //     int excl = solve(nums,n-1)+0;
    //     return max(incl,excl);
    // }

     int solvemem(vector<int>& nums,int n,vector<int>& dp){
        if(n<0)
            return 0;
        if(n==0)
            return nums[0];
        if(dp[n]!=-1)
             return dp[n];
        int incl = solvemem(nums,n-2,dp)+nums[n];
        int excl = solvemem(nums,n-1,dp)+0;
         
         dp[n]=max(incl,excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        // int ans = solve(nums,n-1);
        vector<int> dp(n,-1);
        int ans = solvemem(nums,n-1,dp);
        return ans;
    }
};