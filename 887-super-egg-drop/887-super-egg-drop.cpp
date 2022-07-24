class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));
        int ans = 0;
        while(t[ans][k] < n){
            ans++;
            for(int i=1; i<=k; i++)
                t[ans][i] = t[ans - 1][i - 1] + t[ans - 1][i] + 1;
        }
        return ans;
    }
};