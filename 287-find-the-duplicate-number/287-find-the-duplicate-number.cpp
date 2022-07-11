class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[abs(nums[i])] < 0)
        //         return nums[i];
        //     nums[nums[i]] *= -1;
        // }
        // return -1;
        int slow = nums[0], fast = slow;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};