class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,start=0,end=0;
        int n=s.size();
        unordered_map<char,int>mp;
        
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int count=mp.size();
        int mini=INT_MAX;
        while(j<n){
            
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            if(count==0){
                if(mini>j-i+1){
                    mini=j-i+1;
                    start=i,end=j;
                    
                }else{
                     mini=mini;
                }
                   
                while(count==0){
                        if(mini>j-i+1){
                        mini=j-i+1;
                        start=i,end=j;

                    }else{
                             mini=mini;
                        }
                       
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]>0)
                            count++;
                        i++;
                    }else{
                        i++;
                    }
                    
                }
            }
            j++;
        }
        
        string temp="";
        for(int i=start;i<=end;i++){
            temp+=s[i];
        }
        if(mini==INT_MAX)
            return "";
        else
            return temp;
    }
};