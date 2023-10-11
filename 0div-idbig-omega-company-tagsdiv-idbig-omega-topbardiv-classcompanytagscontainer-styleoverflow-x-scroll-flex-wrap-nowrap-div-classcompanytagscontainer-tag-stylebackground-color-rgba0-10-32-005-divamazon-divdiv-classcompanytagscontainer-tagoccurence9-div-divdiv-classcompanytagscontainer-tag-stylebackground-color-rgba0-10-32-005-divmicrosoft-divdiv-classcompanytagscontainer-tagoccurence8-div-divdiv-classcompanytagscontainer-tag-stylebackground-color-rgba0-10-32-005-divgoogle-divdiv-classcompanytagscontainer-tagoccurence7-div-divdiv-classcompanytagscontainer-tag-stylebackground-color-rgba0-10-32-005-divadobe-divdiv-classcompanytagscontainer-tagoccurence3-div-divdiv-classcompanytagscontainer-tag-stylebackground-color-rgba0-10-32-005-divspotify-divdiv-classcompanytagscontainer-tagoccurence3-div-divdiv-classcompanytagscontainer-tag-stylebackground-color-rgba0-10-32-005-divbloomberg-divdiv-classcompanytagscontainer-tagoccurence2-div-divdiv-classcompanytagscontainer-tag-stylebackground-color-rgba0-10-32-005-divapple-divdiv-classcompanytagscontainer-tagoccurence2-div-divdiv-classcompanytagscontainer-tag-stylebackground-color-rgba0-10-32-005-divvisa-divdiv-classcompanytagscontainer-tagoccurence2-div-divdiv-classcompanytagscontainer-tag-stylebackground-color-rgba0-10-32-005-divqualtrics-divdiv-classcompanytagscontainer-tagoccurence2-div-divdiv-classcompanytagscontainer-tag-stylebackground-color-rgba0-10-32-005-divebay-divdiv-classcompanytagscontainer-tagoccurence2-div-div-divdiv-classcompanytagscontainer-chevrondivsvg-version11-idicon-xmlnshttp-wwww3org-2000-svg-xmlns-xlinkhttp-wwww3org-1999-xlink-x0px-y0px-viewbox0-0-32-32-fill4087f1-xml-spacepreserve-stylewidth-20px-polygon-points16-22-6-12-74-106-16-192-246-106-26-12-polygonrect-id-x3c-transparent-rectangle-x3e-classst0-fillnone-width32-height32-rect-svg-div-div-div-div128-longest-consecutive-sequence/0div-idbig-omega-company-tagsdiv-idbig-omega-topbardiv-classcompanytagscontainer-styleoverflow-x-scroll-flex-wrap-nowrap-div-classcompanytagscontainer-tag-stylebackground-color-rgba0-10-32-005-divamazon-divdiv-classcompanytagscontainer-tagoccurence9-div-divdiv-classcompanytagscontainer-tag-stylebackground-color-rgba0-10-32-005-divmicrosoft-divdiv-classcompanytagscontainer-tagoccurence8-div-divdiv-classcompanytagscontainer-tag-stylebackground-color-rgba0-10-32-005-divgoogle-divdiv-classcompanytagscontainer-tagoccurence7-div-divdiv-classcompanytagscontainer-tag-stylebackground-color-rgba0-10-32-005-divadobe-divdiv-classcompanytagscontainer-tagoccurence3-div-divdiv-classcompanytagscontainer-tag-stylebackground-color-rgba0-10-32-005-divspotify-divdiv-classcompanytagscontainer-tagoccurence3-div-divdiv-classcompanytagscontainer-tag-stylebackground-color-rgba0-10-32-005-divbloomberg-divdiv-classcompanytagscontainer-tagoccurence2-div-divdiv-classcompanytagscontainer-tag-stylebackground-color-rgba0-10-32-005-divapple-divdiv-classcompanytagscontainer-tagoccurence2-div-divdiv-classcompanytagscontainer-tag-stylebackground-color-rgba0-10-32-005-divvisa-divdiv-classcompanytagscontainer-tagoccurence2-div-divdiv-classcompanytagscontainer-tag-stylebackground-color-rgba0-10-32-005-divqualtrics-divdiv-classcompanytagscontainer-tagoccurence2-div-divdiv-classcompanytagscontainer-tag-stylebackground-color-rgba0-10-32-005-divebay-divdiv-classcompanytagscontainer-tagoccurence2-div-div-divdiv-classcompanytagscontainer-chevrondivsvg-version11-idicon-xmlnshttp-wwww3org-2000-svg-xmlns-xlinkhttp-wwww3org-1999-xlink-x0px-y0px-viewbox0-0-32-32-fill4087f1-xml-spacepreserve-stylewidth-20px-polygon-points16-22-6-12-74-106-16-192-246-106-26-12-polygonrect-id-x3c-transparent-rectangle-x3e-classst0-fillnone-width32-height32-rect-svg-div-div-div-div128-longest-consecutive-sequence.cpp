class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        if(n==0)
            return 0;
        int currentCensecutive=1;
        int longestConsecutive=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    currentCensecutive++;
                }
                else{
                    longestConsecutive=max(longestConsecutive,currentCensecutive);
                    currentCensecutive=1;
                }
            }
        }
        return max(longestConsecutive,currentCensecutive);
    }
};