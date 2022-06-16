class Solution {
public:
    string longestPalindrome(string s) {
        int l=0, r=0, temp=0;
        string ans;
        for(int i=0; i<s.length(); i++){
            l=i; r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1 > temp){
                    temp = r-l+1;
                    ans = s.substr(l, temp);
                }
                l--; r++;
            }
            l=i; r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1 > temp){
                    temp = r-l+1;
                    ans = s.substr(l, temp);
                }
                l--; r++;
            }
        }
        return ans;
    }
};