class Solution {
public:
    int count(vector<int>& nums, int s){
        int n = nums.size();
        int t[n+1][s+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=s; j++){
                if(i == 0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=s; j++){
                if(nums[i-1] <=  j)
                    t[i][j] = t[i-1][j] + t[i-1][j - nums[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][s];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i:nums)
            sum += i;
        if (sum < abs(target) ||(sum + target) % 2 != 0)
		    return 0;
        return count(nums, (sum+target) / 2);
    }
};