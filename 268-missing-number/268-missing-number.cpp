class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int x=0;
        // for(int i=0; i<nums.size(); i++){
        //     x = x ^ i ^ nums[i];        
        // }
        // x = x ^ nums.size();
        // if(x==0 && x!=nums.size())
        //     return nums.size();
        // return x;
        
        int res = nums.size();
        for(int i=0; i<nums.size(); i++)
            res += i - nums[i];
        return res;
    }
};