class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto i : nums){
            int temp = abs(i) - 1;
            nums[temp] = nums[temp] > 0 ? nums[temp] * -1 : nums[temp];
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};