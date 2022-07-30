class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string> res;
        int freqs[26] = {}, tmp[26] = {};
        bool isIncluded;
        for (string bit: b) {
            for (char c: bit) {
                tmp[c - 'a']++;
            }
            for (char c: bit) {
                c -= 'a';
                freqs[c] = max(freqs[c], tmp[c]);
                tmp[c] = 0;
            }
        }
        for (string word: a) {
            isIncluded = true;
            for (int i = 0, lmt = word.size(), c; i < lmt; i++) {
                c = word[i] - 'a';
                if (!freqs[c]) continue;
                tmp[c]++;
            }
            for (int i = 0; i < 26; i++) {
                if (freqs[i] > tmp[i]) {
                    isIncluded = false;
                }
                tmp[i] = 0;
            }
            if (isIncluded) res.push_back(word);
        }
        return res;
    }
};