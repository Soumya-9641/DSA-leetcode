class Solution {
public:
    
    void findAns(int idx,vector<int>& candidates,int target, vector<vector<int>>&ans, vector<int>&ds){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            findAns(idx, candidates,target-candidates[idx],ans,ds);
            ds.pop_back();
        }
        findAns(idx+1,candidates,target,ans,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findAns(0,candidates,target,ans,ds);
        return ans;
    }
};