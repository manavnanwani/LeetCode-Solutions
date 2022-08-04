class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int temp = abs(nums[i]) - 1;
            if(nums[temp] < 0)
                ans.push_back(temp + 1);
            else
                nums[temp] = nums[temp] * -1; 
        }
        return ans;
    }
};