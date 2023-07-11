class Solution {
public:
    
    bool ans(vector<int>& nums,int idx , int k,vector<vector<int>>&dp){
        if(k==0)
            return true;
        
        if(idx==0)
            return nums[0]==k;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        bool notake = ans(nums,idx-1,k,dp);
        bool take = false;
        if(nums[idx]<=k){
            take = ans(nums,idx-1,k-nums[idx],dp);
        }
        return dp[idx][k]= take|notake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return ans(nums,n-1,target,dp);
    }
};