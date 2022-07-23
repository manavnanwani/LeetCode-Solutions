class Solution {
public:
    int find(map<pair<int, int>, int> &t, vector<int>& nums, int n, int numSlots, int mask){
        if(t.count({mask, n}))
            return t[{mask, n}];
        else if(n == 0)
            return 0;
        
        int &ans = t[{mask, n}], b, c = 1, p = 1, m = mask;
        while(m){
            b = m % 10;
            m = m / 10;
            if(b > 0)
                ans = max(ans, (nums[n-1] & c) + find(t, nums, n-1, numSlots, mask - p));
            c++;
            p *= 10;
        }
        return ans;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int mask = 2, n = nums.size();
        map<pair<int, int>, int> t;
        for(int i=2; i<=numSlots; i++)
            mask = mask * 10 + 2;
        int temp = find(t, nums, n, numSlots, mask);
        return temp;
    }
};