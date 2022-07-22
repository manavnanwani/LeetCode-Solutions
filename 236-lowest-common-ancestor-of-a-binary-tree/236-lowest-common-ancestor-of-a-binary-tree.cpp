/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL or root == p or root == q)
            return root;
        TreeNode *s1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *s2 = lowestCommonAncestor(root->right, p, q);
        if(s1 and s2)
            return root;
        return s1 ? s1 : s2;

    }
};