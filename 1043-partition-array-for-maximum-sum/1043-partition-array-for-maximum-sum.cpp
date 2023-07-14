class Solution {
public:
    
    int ans(int ind,vector<int>& arr,int k,vector<int>&dp){
        int n = arr.size();
        if(ind==n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        int len=0;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum = len*maxi+ans(j+1,arr,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]= maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return ans(0,arr,k,dp);
    }
};