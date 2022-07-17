class Solution {
public:
    int check(vector<vector<int>> &t, string &text1, string &text2, int i, int j){
        if(i == text1.size() || j == text2.size())
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(text1[i] == text2[j])
            return  t[i][j] = 1 + check(t, text1, text2, i+1, j+1);
        
        return t[i][j] = max(check(t, text1, text2, i, j+1), check(t, text1, text2, i+1, j));
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> t(text1.size(), vector<int>(text2.size(), -1));
        return check(t, text1, text2, 0, 0);
    }
};