class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //brute force
//         vector<int>ans;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int cnt=0;
//             if(ans.size()==0 || ans[0]!=nums[i]){
//                 for(int j=0;j<n;j++){
//                     if(nums[j]==nums[i]){
//                         cnt++;
//                     }
//                 }
//                 if(cnt>(n/3)){
//                     ans.push_back(nums[i]);
//                 }
//             }
//             if(ans.size()==2)
//                 break;
//         }
//         return ans;
        
        
        //using hashmap
        vector<int>ans;
        map<int,int>mpp;
        int n = nums.size();
        int mini =int(n/3)+1;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==mini){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2)
                break;
            
        }
        return ans;
    }
};