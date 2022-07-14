class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<vector<int>> t(n+1, vector<int>(k+1, 0));
        
//         for(int i=0; i<=n; i++)
//             t[i][0] = 1;
        
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=k; j++){
//                 if(nums[i-1] <= j)
//                     t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
//                 else
//                     t[i][j] = t[i-1][j];
//             }
//         }
        
//         return t[n][k] ;
        
        unordered_map<int, int> m;
        int count = 0, sum = 0;
        m[0] = 1;
        for(auto i:nums){
            sum += i;
            count += m[sum - k];
            m[sum]++;
        }
        return count;
    }
};