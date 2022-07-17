class Solution {
public:
//     int check(vector<vector<int>> &t, string &text1, string &text2, int i, int j){
//         if(i == text1.size() || j == text2.size())
//             return 0;
        
//         if(t[i][j] != -1)
//             return t[i][j];
        
//         if(text1[i] == text2[j])
//             return  t[i][j] = 1 + check(t, text1, text2, i+1, j+1);
        
//         return t[i][j] = max(check(t, text1, text2, i, j+1), check(t, text1, text2, i+1, j));
//     }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> t(text1.size()+1, vector<int>(text2.size()+1, 0));
        // return check(t, text1, text2, 0, 0);

        int m = text1.size(), n = text2.size();
        int t[m+1][n+1];
        
        for(int i=0; i<=m; i++)
            t[i][0] = 0;
        for(int i=0; i<=n; i++)
            t[0][i] = 0;
        
        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1] == text2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }   
        }
        
        return t[text1.size()][text2.size()];
    }
};