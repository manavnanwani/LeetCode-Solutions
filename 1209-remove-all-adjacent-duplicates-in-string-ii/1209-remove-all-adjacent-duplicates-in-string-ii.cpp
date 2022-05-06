class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sl;
        for(int i=0; i<s.length(); i++){
            if(!sl.empty() && s[i] == sl.top().first)
                sl.top().second++;
            else
                sl.push({s[i], 1});
            if(sl.top().second == k)
                sl.pop();
        }
        
        string ans = "";
        while(!sl.empty()){
            for(int i=0; i<sl.top().second; i++)
                ans += sl.top().first;
            sl.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};