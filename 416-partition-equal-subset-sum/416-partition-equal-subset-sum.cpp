class Solution {
public:
    bool subset(vector<int>& nums, int k){
        int n = nums.size();
        bool t[n+1][k+1];
        
        for(int i=0; i<=n; i++)
            t[i][0] = true;
        
        for(int i=1; i<=k; i++)
            t[0][i] = false;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(j >= nums[i-1])
                    t[i][j] = t[i-1][j] || t[i-1][j - nums[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][k];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums)
            sum += i;
        if(sum%2 != 0)
            return false;
        return subset(nums, sum/2);
    }
};