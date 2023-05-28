class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count =0;
        int len= pref.size();
        
        for(auto i : words){
            if(i.substr(0,len)==pref){
                count++;
            }
        }
        return count;
    }
};