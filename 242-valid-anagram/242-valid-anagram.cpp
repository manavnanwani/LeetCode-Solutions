class Solution {
public:
    bool isAnagram(string s, string t) {
        int sChars[26] = {0}, tChars[26] = {0};
        int sLen = s.length(), tLen = t.length();
        if(sLen != tLen)
            return false;
        for(int i=0; i<sLen; i++){
            sChars[s[i] - 'a']++;
            tChars[t[i] - 'a']++;
        }
        for(int i=0; i<sLen; i++)
            if(sChars[s[i] - 'a'] != tChars[s[i] - 'a'])
                return false;
        return true;
    }
};