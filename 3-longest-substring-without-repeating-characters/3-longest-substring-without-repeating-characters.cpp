class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, l=0;
        set <char> chars;
        for(int i=0; i<s.length(); i++){
            while(chars.find(s[i]) != chars.end()){
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[i]);
            ans = max(ans, i-l + 1);
        }
        
        return ans;
    }
};