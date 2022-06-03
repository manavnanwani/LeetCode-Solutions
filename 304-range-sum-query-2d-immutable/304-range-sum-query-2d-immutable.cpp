class NumMatrix {
public:
    vector<vector<int>> temp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        temp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=0; i<m; i++){
            int prefix = 0;
            for(int j=0; j<n; j++){
                prefix += matrix[i][j];
                temp[i+1][j+1] = prefix + temp[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1+=1;
        row2+=1;
        col1+=1;
        col2+=1;
        
        int a = temp[row2][col2];
        int aa = temp[row1-1][col2];
        
        int b = temp[row2][col1-1];
        int bb = temp[row1 - 1][col1 - 1];
        
        return a - aa - b + bb;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */