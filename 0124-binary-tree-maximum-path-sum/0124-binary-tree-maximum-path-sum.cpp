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
    
    int ans(TreeNode* root,int& length){
        if(!root)
            return 0;
        // if(root->left==NULL && root->right==NULL )
        //     return root->val;
        int lh= max(0,ans(root->left,length));
        int rh= max(0,ans(root->right,length));
        int value= root->val;
        length= max(length,value+lh+rh);
        
        return max(lh,rh)+value;
    }
    
    int maxPathSum(TreeNode* root) {
        int length=INT_MIN;
        ans(root,length);
        return length;
    }
};