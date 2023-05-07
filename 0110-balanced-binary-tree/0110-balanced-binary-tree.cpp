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
    bool isBalanced(TreeNode* root) {
      
        if(root==NULL)
            return true;
        
        if(height(root)==-1)
            return false;
        
        return true;
        
       
    }
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int maxleft = height(root->left);
        int maxright = height(root->right);
        
        int diff = abs(maxleft-maxright);
        if (maxleft == -1 || maxright == -1)  return -1;
        if(diff>1)
            return -1;
        
        return max(maxleft,maxright)+1;
    }
};