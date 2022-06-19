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
    int pIndex = 0;
    TreeNode* construct(vector<int>& preorder, int start, int end, unordered_map<int,int> &m){
        if(start>end)
            return NULL;
        
        int x = preorder[pIndex++];
        TreeNode* node = new TreeNode(x);
        int iIndex = m[x];
        node->left = construct(preorder, start, iIndex-1, m);
        node->right = construct(preorder, iIndex+1, end, m);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int> m;
        int n = inorder.size();
        for(int i=0; i<inorder.size(); i++)
            m[inorder[i]] = i;
        return construct(preorder, 0, n-1, m);
    }
};