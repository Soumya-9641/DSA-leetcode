class Solution {
public:
    int subtractProductAndSum(int n) {

        int product=1;
        int sum = 0;
        while(n!=0){
            int rem1=n%10;
            product*=rem1;
            sum+=rem1;
            n=n/10;
        }
        
        int ans =product-sum;
        return ans;
    }
};