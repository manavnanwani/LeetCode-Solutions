class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = 9999999999, ans=0;
        for(int i = 0; i < prices.size(); i++){
            mi = min(mi,prices[i]);
            ans = max(prices[i]-mi,ans);
        }
        return ans;
    }
};