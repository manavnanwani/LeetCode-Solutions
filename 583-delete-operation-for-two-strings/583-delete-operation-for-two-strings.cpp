class Solution {
public:
    int minDistance(string str1, string str2) {
        int s1 = str1.size(), s2 = str2.size();
	    int t[s1+1][s2+1];
	    
	    for(int i=0; i<=s1; i++){
	        for(int j=0; j<=s2; j++){
	            if(i == 0 or j == 0)
	                t[i][j] = 0;
	            else if(str1[i-1] == str2[j-1])
	                t[i][j] = 1 + t[i-1][j-1];
	            else
	                t[i][j] = max(t[i-1][j], t[i][j-1]);
	        }
	    }
	    
	    return s1 + s2 - (2 * t[s1][s2]);
    }
};