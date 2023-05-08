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
    int sum=0;
public:
    
    void travelsum(TreeNode*root){
        if(!root)
            return ;
        
        if(root->right)
            travelsum(root->right);
        sum+=root->val;
        root->val=sum;
        
        if(root->left)
            travelsum(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        travelsum(root);
        return root;
    }
};