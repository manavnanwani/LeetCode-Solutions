class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        for(int i=0; i<=n; i++){
            int temp = i, bin = 0;
            while(temp){
                temp = temp & (temp-1);
                bin++;
            }
            ans.push_back(bin);
        }
        
        // vector <int> ans(n+1,0);
        // int offset = 0;
        // for(int i=1; i<=n; i++){
        //     if(offset*2 == i)
        //         offset = i;
        //     ans[i] = 1 + ans[i-offset];
        // }
        
        return ans;
    }
};