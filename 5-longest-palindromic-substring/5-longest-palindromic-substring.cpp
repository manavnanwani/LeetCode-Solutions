class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        string check;
        int aLen = 0,cLen = 0;
        int l,r;
        for(int i=0; i<s.length(); i++){
            l=i, r=i;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                // cLen = r - l + 1; 
                // check = s.substr(l,cLen);
                if(r-l+1 > aLen){
                    aLen = r - l + 1;
                    ans = s.substr(l, aLen);
                    // aLen = cLen;                    
                }
                l--;
                r++;
            }

            l=i, r=i+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                // cLen = r - l + 1; 
                // check = s.substr(l,r-l+1);
                if(r-l+1 > aLen){
                    aLen = r - l + 1;
                    ans = s.substr(l, aLen);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};