class Solution {
public:
    
    int ans(vector<vector<int>>&mem,int i,int j,string &s){
        if(i>=j)
            return 1;
        if(mem[i][j]>=0)
            return mem[i][j];
        if(s[i]==s[j]){
           return mem[i][j]= ans(mem,i+1,j-1,s);
        }
        
            return 0;
    
    }
    
    int solve(string &s){
        int count=0;
        vector<vector<int>>mem(s.size(),vector<int>(s.size(),-1));
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                count+=ans(mem,i,j,s);
            }
        }
        return count;
    }
    
    int countSubstrings(string s) {
        
        return solve(s);
    }
};