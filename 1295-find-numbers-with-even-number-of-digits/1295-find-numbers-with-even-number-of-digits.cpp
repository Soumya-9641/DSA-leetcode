class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
       
       int output=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(nums[i]>0)
            {
                count++;
                nums[i]/=10;
            }
            if(count%2==0)
                output++;
        }
        return output;
    }
};