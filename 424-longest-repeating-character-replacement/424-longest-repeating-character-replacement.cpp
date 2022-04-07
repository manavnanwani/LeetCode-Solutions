class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, l=0, r=0, n=s.size(), count=0;
        unordered_map<char, int> ss;
        while(r<n){
            ss[s[r]]++;
            count= max(count, ss[s[r]]);
            int cLen = r-l+1;
            if(cLen - count > k){
                ss[s[l]]--;
                l++;
            }
            cLen = r-l+1;
            ans = max(ans, cLen);
            r++;
        }
        return ans;
    }
};