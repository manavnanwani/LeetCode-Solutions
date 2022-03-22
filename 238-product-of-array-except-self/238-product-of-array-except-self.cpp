class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int pre=1,post=1;
        for(int i=0; i<nums.size(); i++){
            answer[i] = pre * answer[i];
            pre = pre * nums[i];
        }
        for(int i=nums.size()-1; i>=0; i--){
            answer[i] = answer[i] * post;
            post = post * nums[i];
        }
        return answer;
    }
};