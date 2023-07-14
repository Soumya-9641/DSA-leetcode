class Solution {
public:
    
    bool isPalindrom(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int ans(int i,string &s,int n, vector<int>&dp){
        if(i==n)
            return 0;
        int minCost=INT_MAX;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i;j<n;j++){
            if(isPalindrom(i,j,s)){
                int cost=1+ans(j+1,s,n,dp);
                minCost = min(cost,minCost);
            }
        }
        return dp[i]= minCost;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return ans(0,s,n,dp)-1;
    }
};