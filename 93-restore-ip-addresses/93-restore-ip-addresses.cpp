class Solution {
public:
    void backtrack(vector<string> &ans, string &s, int i, int dots, string curr, int &n){
        if(dots == 4 and i == n){
            ans.push_back(curr.substr(0, curr.size() - 1));
            return;
        }
        if(dots > 4)
            return;
        
        for(int j = i; j < min(i+3, n); j++){
            string temp = s.substr(i, j-i+1);
            int num = stoi(temp);
            if(num < 256 and (i == j or s[i] != '0'))
                backtrack(ans, s, j + 1, dots + 1, curr + temp + ".", n);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();
        
        if(n>12)
            return ans;
        
        backtrack(ans, s, 0, 0, "", n);
        return ans;
    }
};