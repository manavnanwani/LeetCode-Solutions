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
    void add(TreeNode* root, priority_queue<int> &maxh, int k){
        if(root==NULL)
            return;
        maxh.push(root->val);
        if(maxh.size() > k)
            maxh.pop();
        add(root->left, maxh, k);
        add(root->right, maxh, k);

    }
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> maxh;
        add(root, maxh, k);
        return maxh.top();
    }
};