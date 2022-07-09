class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size(), ans = nums[0];
        priority_queue<pair<int,int>> h;
        h.push({nums[0],0});
        for(int i=1; i<n; i++){
            while(h.top().second + k < i)
                h.pop();
            ans = nums[i] + h.top().first;
            h.push({ans, i});
        }
        return ans;
    }
};