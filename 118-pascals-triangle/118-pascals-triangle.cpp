class Solution {
public:
    vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans;
//         ans.push_back({1});
//         if(numRows == 1)
//             return ans;
//         ans.push_back({1,1});
//         if(numRows == 2)
//             return ans;
        
//         numRows -= 2;
//         while(numRows--){
//             vector<int> t = ans.back();
//             vector<int> temp = t;
//             int n = t.size() - 2;
//             for(int i=0; i<n; i++){
//                 auto pos = t.begin() + i;
//                 temp.insert(pos, t[i] + t[i+1]);
//             }
//             ans.push_back(temp);
//         }
//         return ans;

        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j=1; j<i; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans;

    }
};