class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp1,mp2;
        int k= p.size();
        for(int i=0;i<k;i++){
            mp1[p[i]]++;
            mp2[s[i]]++;
        }
        
        vector<int>ans;
         if(mp1==mp2)
                ans.push_back(0);
        for(int i=k;i<s.size();i++){
           
            mp2[s[i]]++;
            mp2[s[i-k]]--;
            
            if(mp2[s[i-k]]==0)
                mp2.erase(s[i-k]);
            if(mp1==mp2)
                ans.push_back(i-k+1);
        }
        return ans;
    }
};