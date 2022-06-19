class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        int l=0, r=products.size()-1;
        for(int i=0; i<searchWord.size(); i++){
            char c = searchWord[i];
            while(l<=r && (products[l].length() <= i || products[l][i] != c))
                l++;
            while(l<=r && (products[r].length() <= i || products[r][i] != c))
                r--;
            
            vector<string> temp;
            for(int j=0; j<min(3,r-l+1); j++)
                temp.push_back(products[l+j]);  
            ans.push_back(temp);
        }
        return ans;
    }
};