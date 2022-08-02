class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
	    int t[n+1][n+1];
	    string s1 = s;
        reverse(s1.begin(), s1.end());
        
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=n; j++){
	            if(i == 0 or j == 0)
	                t[i][j] = 0;
	            else if(s[i-1] == s1[j-1])
	                t[i][j] = 1 + t[i-1][j-1];
	            else
	                t[i][j] = max(t[i-1][j], t[i][j-1]);
	        }
	    }
	    
	    return t[n][n];
    }
};