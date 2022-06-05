class Solution {
public:
    int backtrack(vector<bool> &col, vector<bool> &pDia, vector<bool> &nDia, int r){
        int ans = 0, n=size(col);
        if(r == n) return 1;
        
        for(int i=0; i<n; i++){
            if(!col[i] && !pDia[r-i+n-1] && !nDia[r+i]){
                col[i] = pDia[r-i+n-1] = nDia[r+i] = true;
                ans += backtrack(col, pDia, nDia, r+1);
                col[i] = pDia[r-i+n-1] = nDia[r+i] = false;

            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        vector<bool> col(n), pDia(2*n-1), nDia(2*n-1);
        return backtrack(col, pDia, nDia, 0);
    }
};