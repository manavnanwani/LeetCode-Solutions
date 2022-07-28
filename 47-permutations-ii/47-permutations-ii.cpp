class Solution {
public:
    void help(vector<vector<int>> &ans, int i, int n, vector<int> &nums){
        if(i == n){
            if(find(ans.begin(), ans.end(), nums) == ans.end())
                ans.push_back(nums);
            return;
        }
        for(int j=i; j<=n; j++){
            swap(nums[i], nums[j]);
            help(ans, i+1, n, nums);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        help(ans, 0, n-1, nums);
        return ans;
    }
};