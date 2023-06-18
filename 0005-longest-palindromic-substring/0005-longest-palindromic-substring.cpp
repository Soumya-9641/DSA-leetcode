class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int n= s.length();
        int max_len = 1;
        int st=0;
        int end=0;
        //odd length 
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }else{
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                max_len = len;
                st=l+1;
                end = r+1;
                
            }
        }
        //for even
         for(int i=0;i<n;i++){
            int l=i,r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }else{
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                max_len = len;
                st=l+1;
                end = r+1;
                
            }
        }
        return s.substr(st,max_len);
    }
};