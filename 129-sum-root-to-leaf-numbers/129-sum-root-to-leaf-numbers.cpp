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
    void find(TreeNode* root, vector<int> &temp, int curr){
        if(root == NULL)
            return;
        curr = curr * 10 + root->val;
        find(root->left, temp, curr);
        find(root->right, temp, curr);
        if(root->left == NULL and root->right == NULL)
            temp.push_back(curr);
        curr /= 10;
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> store;
        find(root, store, 0);
        int ans = accumulate(store.begin(), store.end(), 0);
        return ans;
    }
};