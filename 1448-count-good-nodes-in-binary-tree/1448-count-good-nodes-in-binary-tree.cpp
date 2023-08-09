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
    
    int search(TreeNode* cur,int max){
        if(!cur)
            return 0;
        int count=0;
        if(cur->val>=max){
            count+=1;
            max=cur->val;
            
        }
        count+=search(cur->left,max);
        count+=search(cur->right,max);
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int goodnode=1;
        goodnode+=search(root->left,root->val);
        goodnode+=search(root->right,root->val);
        return goodnode;
    }
};