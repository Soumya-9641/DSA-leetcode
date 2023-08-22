class Solution {
public:
    int jump(vector<int>& nums) {
        int maxsofar=0;
        int curjump=0;
        int jump=0;
        for(int i=0;i<nums.size()-1;i++){
            maxsofar=max(maxsofar,i+nums[i]);
            
            if(i==curjump){
                jump++;
                curjump=maxsofar;
                
            }
        }
        return jump;
    }
};