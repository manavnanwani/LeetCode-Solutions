class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = 0, last=nums.size() - 1, ans = nums[0], mid=0;
        while(first <= last){
            if(nums[first] < nums[last]){
                ans = std::min(ans, nums[first]);
                break;
            }
            mid = round((first+last)/2);
            ans = std::min(ans, nums[mid]);
            if(nums[mid] >= nums[first])
                first = mid + 1;
            else
                last = mid - 1; 
        }
        return ans;
    }
};