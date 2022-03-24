class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(),sum=0;
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        int l,r;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            l=i+1;
            r = n-1;
            
            while(l<r){
                sum = nums[i]+nums[l]+nums[r];
                if(sum == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    l++;
                    while(nums[l] == nums[l-1] && l<r)
                        l++;
                }
                else if(sum>0)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};