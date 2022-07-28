class Solution {
public:
    bool isAnagram(string s, string t) {
        int sa[26] = {0}, ta[26] = {0};
        int sl = s.size(), tl = t.size();
        if(sl != tl)
            return false;
        for(int i = 0; i<sl; i++){
            sa[s[i] - 'a']++;            
            ta[t[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(ta[i] != sa[i])
                return false;
        }
        return true;
    }
};