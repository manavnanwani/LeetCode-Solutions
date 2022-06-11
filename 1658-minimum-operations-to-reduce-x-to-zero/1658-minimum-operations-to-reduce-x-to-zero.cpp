class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0, n=nums.size(), i=0, temp=0, len=0;
        bool found = false;
        for(int i:nums)
            sum+=i;
        int target = sum-x;
        for(int j=0; j<n; j++){
            temp += nums[j];
            while(i<=j && temp>target){
                temp -= nums[i];
                i++;
            }
            if(temp == target){
                found = true;
                len = max(len, j-i+1);
            }
        }
        return found ? n-len : -1;
    }
};