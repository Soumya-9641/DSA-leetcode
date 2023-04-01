/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        else if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        else{
            int middle = nums.size()/2;
            TreeNode *root = new TreeNode(nums[middle]);
            
            vector<int> leftInt (nums.begin(),nums.begin()+middle);
             vector<int> rightInt (nums.begin()+middle+1,nums.end());
                                       
        root->left = sortedArrayToBST(leftInt);
          root->right = sortedArrayToBST(rightInt);
            
            return root;
        }
    }
};