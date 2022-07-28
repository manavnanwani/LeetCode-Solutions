class Solution {
public:
    void find(vector<string> &ans, int open, int close, int n, string curr){
        int s = curr.size();
        if(s == n*2){
            ans.push_back(curr);
            return;
        }
        if(open < n)
            find(ans, open+1, close, n, curr + "(");
        if(open > close)
            find(ans, open, close + 1, n, curr + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(ans, 0, 0, n, "");
        return ans;
    }
};