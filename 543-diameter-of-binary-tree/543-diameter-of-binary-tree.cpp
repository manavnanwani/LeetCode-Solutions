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
    int find(TreeNode *root, int &ans){
        if(root == NULL)
            return 0;
        int l = find(root->left, ans);
        int r = find(root->right, ans);
        int temp = max(l,r) + 1;
        // int res = max(l + r, temp);
        ans = max(ans, l + r);
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        find(root, ans);
        return ans;
    }
};