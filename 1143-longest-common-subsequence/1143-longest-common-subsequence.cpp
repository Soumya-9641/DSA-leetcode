class Solution {
public:
    
    int lcsUtil(string &text1,string &text2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)
            return 0;
        
        int count=0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        //if matched
        if(text1[idx1]==text2[idx2])
            return   dp[idx1][idx2] = 1+ lcsUtil(text1,text2,idx1-1,idx2-1,dp);
        
       
        
        //if not matched
        else
             return dp[idx1][idx2] = 0+ max(lcsUtil(text1,text2,idx1-1,idx2,dp),lcsUtil(text1,text2,idx1,idx2-1,dp));
        
        
    }
       
        
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int string1 = text1.size();
        int string2 = text2.size();
        vector<vector<int>>dp(string1,vector<int>(string2,-1));
        return lcsUtil(text1,text2,string1-1,string2-1,dp);
    }
};