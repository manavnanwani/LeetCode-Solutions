class Solution {
public:
    void find(vector<vector<int>> &ans, vector<int> nums, int n, int i){
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<=n; j++){
            swap(nums[i], nums[j]);
            find(ans, nums, n, i+1);
            swap(nums[i], nums[j]);

        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size() - 1;
        find(ans, nums, n, 0);
        return ans;
    }
};