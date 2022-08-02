class Solution {
public:
    
    void solve(vector<vector<int>> &ans, vector<int> curr, int currSum, int currIndex, int &target, vector<int> &candidates){
        if(currSum > target)
            return;
        if(currSum == target){
            ans.push_back(curr);
            return;
        }
        
        for(int i = currIndex; i < candidates.size(); i++){
            currSum += candidates[i];
            curr.push_back(candidates[i]);
            solve(ans, curr, currSum, i, target, candidates);
            currSum -= candidates[i];
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, 0, 0, target, candidates);
        return ans;
    }
};