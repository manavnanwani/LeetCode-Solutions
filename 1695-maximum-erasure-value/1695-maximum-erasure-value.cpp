class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, temp=0;
        unordered_set <int> m;
        int i=0,j=0;
        while(j<nums.size()){
            while(m.count(nums[j]) > 0){
                m.erase(nums[i]);
                temp -= nums[i];
                i++;
            }
            
            temp += nums[j];
            m.insert(nums[j++]);
            ans = max(ans, temp);
        }
        
        return ans;
    }
};