class Solution {
public:
    int t[51][51][52];
    int mod = 1e9 + 7;
    
    int check(int &m, int &n, int mm, int r, int c){
        if(r == m || c == n || r < 0 || c < 0)
            return 1;
        if(mm == 0)
            return 0;
        if(t[r][c][mm] != -1)
            return t[r][c][mm];
        
        int ans = 0;
        
        ans = (ans + check(m, n, mm - 1, r+1, c)) % mod;
        ans = (ans + check(m, n, mm - 1, r-1, c)) % mod;
        ans = (ans + check(m, n, mm - 1, r, c+1)) % mod;
        ans = (ans + check(m, n, mm - 1, r, c-1)) % mod;
        
        return t[r][c][mm] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int r, int c) {
        memset(t, -1, sizeof(t));
        return check(m,n,maxMove,r,c);   
    }
};