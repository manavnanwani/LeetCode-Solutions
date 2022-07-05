class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        priority_queue<int> h;
        for(auto i:nums)
            h.push(i);
        
        int ans = 1, temp = 1, prev;
        while(h.size() > 1){
            prev = h.top();
            h.pop();
            if(prev == h.top() + 1){
                temp++;
                ans = max(temp, ans);
            }
            else if(prev == h.top())
                continue;
            else
                temp = 1;
        }
        return ans;
    }
};