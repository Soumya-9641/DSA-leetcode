class Solution {
public:
    
    int ans(vector<int>& nums,int target,int n,int index,int cur_sum,vector<vector<int>>&dp){
    if(index==n){
        if(cur_sum==target){
            return 1;
        }
        return 0;
    }
    
    if(dp[index][cur_sum+1001]!=INT_MIN){
        return dp[index][cur_sum+1001];
    }
     int positive = ans(nums, target,n, index + 1, cur_sum + nums[index], dp);
        int negative = ans(nums, target,n, index + 1, cur_sum - nums[index], dp);
    dp[index][cur_sum+1001]=positive+negative;
    return dp[index][cur_sum+1001];
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        vector<vector<int>>dp(n,vector<int>(2001,INT_MIN));
            return ans (nums,target,n,0,0,dp);
    }
};