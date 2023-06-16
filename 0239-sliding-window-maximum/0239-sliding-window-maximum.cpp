class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //naive approach
        // vector<int>ans;
        // int n = nums.size();
        // for(int i=0;i<(n-k+1);i++){
        //     int max= nums[i];
        //     for(int j=i;j<=(i+k-1);j++){
        //         if(max<nums[j]){
        //             max= nums[j];
        //         }
        //     }
        //     ans.push_back(max);
        // }
        // return ans;
        
        //optimal
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            //out of bound case
            if(!dq.empty() && dq.front()==(i-k)){
                dq.pop_front();
            }
            //delete all element lesser than index i
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
        
        
    }
};