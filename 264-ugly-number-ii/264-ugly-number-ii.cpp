class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(1);
        int temp = n-1, i=0, j=0, k=0;
        while(temp--){
            int a = dp[i] * 2;
            int b = dp[j] * 3;
            int c = dp[k] * 5;
            int ans = min(a,min(b,c));
            dp.push_back(ans);
            
            if(a == ans) i++;
            if(b == ans) j++;
            if(c == ans) k++;
        }
        return dp[n-1];
    }
    
};