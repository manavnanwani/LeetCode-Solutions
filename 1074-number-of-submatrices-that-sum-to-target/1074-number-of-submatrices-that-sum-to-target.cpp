class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& M, int T) {
        // int n = matrix.size(), m = matrix[0].size(), ans = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=1; j<m; j++){
        //         matrix[i][j] += matrix[i][j-1];
        //     }
        // }
        // unordered_map<int,int> ma;
        // for(int i=0; i<m; i++){
        //     for(int j=i; j<m; j++){
        //         ma.clear();
        //         ma[0] = 1;
        //         int temp = 0;
        //         for(int k = 0; k<n; k++){
        //             temp += matrix[k][j] + (i>0 ? matrix[k][i-1] : 0);
        //             ans += ma.find(temp - target) != ma.end() ? ma[temp - target] : 0;
        //             ma[temp]++;
        //         }
        //     }
        // }
        // return ans;
        
        
        int xlen = M[0].size(), ylen = M.size(), ans = 0;
        unordered_map<int, int> res;
        for (int i = 0; i < ylen; i++)
            for (int j = 1; j < xlen; j++)
                M[i][j] += M[i][j-1];
        for (int j = 0; j < xlen; j++)
            for (int k = j; k < xlen; k++) {
                res.clear();
                res[0] = 1;
                int csum = 0;
                for (int i = 0; i < ylen; i++) {
                    csum += M[i][k] - (j ? M[i][j-1] : 0);
                    ans += res.find(csum - T) != res.end() ? res[csum - T] : 0;
                    res[csum]++;
                }
            }
        return ans;
        
        
        // Similar to Subarray Sum equals K; First calculate prefix sum and them find in 
        // every row if subarray equals target. 
    }
};