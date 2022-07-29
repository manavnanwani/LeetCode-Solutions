class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string temp = convert(pattern);
        for(auto x : words){
            if(temp == convert(x))
                ans.push_back(x);
        }
        return ans;
    }
    
    string convert(string x){
        unordered_map<char, char> m;
        char c = 'a';
        for(auto ch : x)
            if(!m.count(ch))
                m[ch] = c++;
        
        for(auto &ch : x)
            ch = m[ch];
        
        return x;
    }
};