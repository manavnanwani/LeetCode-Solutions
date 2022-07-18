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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            int a = q.front().second;
            int b = q.back().second;
            
            ans = max(ans, b-a+1);
            for(int i=0; i<n; i++){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                
                int temp = p.second - a;
                if(p.first -> left != NULL)
                    q.push({p.first->left,(long long) 2*temp + 1});
                if(p.first -> right != NULL)
                    q.push({p.first->right,(long long) 2*temp + 2});
                
            }
        }
        return ans;
    }
};