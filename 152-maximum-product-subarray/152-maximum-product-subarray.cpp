class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), ma=1, mi=1, ans=*max_element(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                ma = 1;
                mi = 1;
                continue;
            }
            int temp = nums[i] * ma;
            ma = max(nums[i], max(nums[i] * ma, nums[i] * mi));
            mi = min(nums[i], min(temp, nums[i] * mi));
            ans = max(ans , ma); 
        }
        return ans;
    }
};