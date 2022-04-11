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
    int find(TreeNode* root){
        if(!root) return 0;
        int l = find(root->left);
        int r = find(root->right);
        
        if(l==0 or r==0)
            return 1+max(l,r);
        return 1+min(l,r);
    }
    
    int minDepth(TreeNode* root) {
        return find(root);
    }
};