class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string, vector<string>> m;
        for(auto i:strs){
            string temp = i;
            sort(i.begin(), i.end());
            m[i].push_back(temp);
        }
        for(auto i: m)
            ans.push_back(i.second);
        return ans;
    }
};