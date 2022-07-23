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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int c = 0;
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            if(c % 2 != 0)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            c++;
        }
        return ans;
    }
};