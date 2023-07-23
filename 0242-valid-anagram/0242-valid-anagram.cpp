class Solution {
public:
    bool isAnagram(string s, string t) {
        //using sorting O(logn)
        // sort(t.begin(),t.end());
        // sort(s.begin(),s.end());
        // if(t==s)
        //     return true;
        // return false;
        
        //using hasmap
        int n=s.size();
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int>counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto count:counts){
            if(count.second)
                return false;
            
        }
        return true;
    }
};