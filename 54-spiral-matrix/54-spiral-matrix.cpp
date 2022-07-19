class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> ans;
        int m = ma.size();
        int n = ma[0].size();
        
        int l = 0, r = n-1, t = 0, b = m-1, k = 0;
        
        while (ans.size() != m*n){
            if(k == 0){
                for(int i = l; i <= r; i++)
                    ans.push_back(ma[t][i]);            
                k = 1;
                t++;
            }
            else if(k == 1){
                for(int i = t; i <= b; i++)
                    ans.push_back(ma[i][r]); 
                k = 2;
                r--;
            }
            else if(k == 2){
                for(int i = r; i >= l; i--)
                    ans.push_back(ma[b][i]); 
                k = 3;
                b--;
            }
            else if(k == 3){
                for(int i = b; i >=t; i--)
                    ans.push_back(ma[i][l]); 
                k = 0;
                l++;
            }
            
                
        }
        return ans;
    }
};