class Solution {
public:
    bool isPalindrome(int x) {
         long rev=0;
          long  rem;
       if(x<0){
           return false;
       }
            int num = x;
        
        while(x!=0){
            
          rem = x%10;
            rev = rev*10+rem;
            x= x/10;
        }
        if(num==rev){
            return true;
        }else{
          return  false;
        }
    }
};