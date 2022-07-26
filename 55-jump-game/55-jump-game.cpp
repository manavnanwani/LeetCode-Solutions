class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            j++;
            if(nums[i] >= j)
                j = 0;
        }
        if(j == 0)
            return true;
        return false;
    }
};