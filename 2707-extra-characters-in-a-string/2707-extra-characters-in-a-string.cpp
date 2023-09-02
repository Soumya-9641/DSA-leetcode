class Solution {
public:
    
    int solve(string &s,unordered_map<string,int>&map,int index, vector<int>&dp){
        //base case
        if(index>=s.size())
            return 0;
        string subStr="";
        if(dp[index]!=-1)
            return dp[index];
        int minExtra= s.size();
        
        for(int i=index;i<s.size();i++){
            subStr.push_back(s[i]);
            int curExtra= (map.count(subStr)?0:subStr.size());
            int nextStr= solve(s,map,i+1,dp);
            int total = curExtra+nextStr;
            minExtra= min(minExtra,total);
        }
        return dp[index]= minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
       unordered_map<string,int>map;
        vector<int>dp(s.size(),-1);
        for(string& word: dictionary ){
            map[word]++;
        }
        int ans = solve(s,map,0,dp);
        return ans;
    }
};