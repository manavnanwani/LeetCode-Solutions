class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans=0;
        vector<vector<int>> ch(n,vector<int>(26));
        for(int i=0; i<n; i++)
            for(int j=0; j<words[i].size(); j++)
                ch[i][words[i][j] - 'a']++;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool check = true;
                for(int k=0; k<26; k++){
                    if(ch[i][k] > 0 && ch[j][k] > 0)
                        check = false;
                }
                if(check){
                    int temp = words[i].size()*words[j].size();
                    ans = max(ans,temp);
                }
                    
            }
        }
        return ans;
    }
};