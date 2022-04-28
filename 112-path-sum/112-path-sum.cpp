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
    // bool check(TreeNode* root, int targetSum, int currentSum){
    //     if(root == NULL)
    //         return false;
    //     if (root->left == NULL and root->right == NULL and targetSum == currentSum+root->val)
    //         return true;
    //     else
    //         return false;
    //     return (check(root->left, targetSum, currentSum + root->val) || check(root->right, targetSum, currentSum + root->val));
    // }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(!root)
        //     return false;
        // return check(root, targetSum, 0);
        
        if(!root)
            return false;
        if(root->val == targetSum and !root->left and !root->right)
            return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};