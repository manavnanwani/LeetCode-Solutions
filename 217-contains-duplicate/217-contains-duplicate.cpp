class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s = {};
        for(int i=0;i<nums.size();i++){
            auto pos = s.find(nums[i]);
            if(pos==s.end())
                s.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};