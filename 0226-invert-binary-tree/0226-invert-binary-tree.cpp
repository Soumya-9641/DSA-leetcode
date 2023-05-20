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
    TreeNode* invertTree(TreeNode* root) {
        if(nullptr==root)
            return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node->left!=NULL){
                q.push(node->left);
            }
             if(node->right!=NULL){
                q.push(node->right);
            }
            
            TreeNode *temp= node->left;
            node->left=node->right;
            node->right=temp;
        }
        return root;
    }
};