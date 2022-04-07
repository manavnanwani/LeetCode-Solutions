class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0,1);
        int l,r;
        for(int i=0; i<s.length(); i++){
            l=i, r=i;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                string check = s.substr(l,r-l+1);
                if(check.length() > ans.length())
                    ans = check;
                l--;
                r++;
            }

            l=i, r=i+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                string check = s.substr(l,r-l+1);
                if(check.length() > ans.length())
                    ans = check;
                l--;
                r++;
            }
        }
        return ans;
    }
};