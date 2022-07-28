class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return b[0] > a[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        for(auto i : intervals){
            if(ans.size() == 0){
                ans.push_back(i);
                continue;            
            }
            vector<int> temp = ans.back();
            if(i[0] <= temp[1]){
                temp[1] = max(i[1], temp[1]);
                ans.pop_back();
                ans.push_back(temp);
            }
            else
                ans.push_back(i);
        }
        return ans;
    }
};