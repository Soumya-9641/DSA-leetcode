class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxprofit = 0;
        int buy = INT_MAX;
        for(int i=0;i<n;i++){
            buy = min(buy,prices[i]);
            maxprofit = max(maxprofit,prices[i]-buy);
        }
        return maxprofit;
    }
};