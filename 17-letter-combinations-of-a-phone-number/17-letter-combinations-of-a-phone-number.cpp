class Solution {
public:
    
    vector<string> v= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void find(vector<string> &ans, int i, int &s, string &digits, string curr){
        if(i == s){
            ans.push_back(curr);
            return;
        }
        string temp = v[digits[i] - '0'];
        for(int j = 0; j < temp.size(); j++)
            find(ans, i+1, s, digits, curr + temp[j]);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int s = digits.size();
        if(s == 0)
            return ans;
        
        find(ans, 0, s, digits, "");
        return ans;
    }
};