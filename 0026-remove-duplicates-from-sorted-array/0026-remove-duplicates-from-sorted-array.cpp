class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums.at(i)==nums.at(i-1))
                count++;
         
             else 
                nums.at(i-count)=nums.at(i);
                
            
        }
        return nums.size()-count;
    }
};