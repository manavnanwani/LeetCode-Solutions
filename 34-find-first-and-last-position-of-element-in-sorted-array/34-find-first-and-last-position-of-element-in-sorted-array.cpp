class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1, l = 0, r = nums.size() - 1, mid;
        if(r == -1)
            return {-1, -1};
        while(l <= r){
            mid = (r+l) / 2;
            if(nums[mid] == target){
                first = last = mid;
                int j = mid - 1;
                while(j >= 0 and nums[j] == target){
                    first--;
                    j--;
                }
                // if(j != mid)
                //     first++;
                j = mid + 1;
                while(j < nums.size() and nums[j] == target){
                    last++;
                    j++;                    
                }
                // if(j != mid)
                //     last--;
                break;
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
                
        }
        return {first, last};
    }
};