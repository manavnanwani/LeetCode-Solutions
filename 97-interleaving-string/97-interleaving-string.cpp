class Solution {
public:
    bool check(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>&memo){
        if(i==s1.size() && j==s2.size() && k == s3.size())
            return true;
        if(i>s1.size() || j>s2.size())
            return false;
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(s1[i] == s3[k] && s2[j] == s3[k])
            return memo[i][j] = check(s1,s2,s3,i+1,j,k+1,memo) || check(s1,s2,s3,i,j+1,k+1,memo);
        else if(s1[i] == s3[k])
            return memo[i][j] = check(s1,s2,s3,i+1,j,k+1,memo);
        else if(s2[j] == s3[k])
            return memo[i][j] = check(s1,s2,s3,i,j+1,k+1,memo);
        else
            return memo[i][j] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.size()+1,(vector<int>(s2.size()+1, -1)));
        return check(s1,s2,s3,0,0,0,memo);
    }
};