class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> ma;
        for(auto i:words)
            ma[i]++;
        int ans = 0;
        for(auto i : ma){
            int c1 = 0, c2 = 0;
            int n = s.size();
            int m = i.first.size();
            while(c1 < n and c2 < m){
                if(s[c1] == i.first[c2]){
                    c1++;
                    c2++;
                }
                else
                    c1++;
            }
            if(c2 == m)
                ans += i.second;
        }
        return ans;
    }
};