
typedef long long int l1;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        l1 ans =0;
        int n=nums.size();
        int nxt= 1e9+7;
        for(int j=n-1;j>=0;j--){
            if(nums[j]<=nxt){
                nxt=nums[j];
                continue;
            }
            l1 parts =ceil(nums[j]/(double)nxt);
            ans+= parts-1;
            nxt=nums[j]/parts;
        }
        return ans;
    }
};