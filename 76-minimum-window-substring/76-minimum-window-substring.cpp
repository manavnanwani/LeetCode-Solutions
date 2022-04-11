class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size() || t=="")
            return "";
        unordered_map <char,int> mt, window;
        int l=0, r=0, temp=0, rans=1000000, lans=1;
        for(auto i:t)
            mt[i]++;
        for(r=0; r<s.length(); r++){
            if(mt.find(s[r]) != mt.end()){
                window[s[r]]++;
                if(window[s[r]] <= mt[s[r]])
                    temp++;
            }
            
            if(temp >= t.length()){
                while(mt.find(s[l]) == mt.end() || window[s[l]] > mt[s[l]]){
                    window[s[l]]--;
                    l++;
                }
                
                if(r-l+1 < rans-lans+1)
                    rans = r, lans = l;
            }
        }
        if(rans == 1000000) return "";
        int len = rans-lans+1;
        return s.substr(lans, len);
    }
};