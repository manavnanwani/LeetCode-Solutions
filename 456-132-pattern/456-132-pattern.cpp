class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int mi = nums[0];
        stack<pair<int, int>> s;
        for(int i = 1; i<nums.size(); i++){
            while(!s.empty() and nums[i] >= s.top().first)
                s.pop();
            if(!s.empty() and nums[i] > s.top().second)
                return true;
            s.push({nums[i], mi});
            mi = min(mi, nums[i]);
        }
        return false;
    }
};