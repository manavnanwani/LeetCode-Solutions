class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        
        long int ans = 0, maxWidth=0, maxHeight=0;
        for(int i=0, prev=0; i<horizontalCuts.size(); i++){
            maxWidth = max(maxWidth, (long int) horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        for(int i=0, prev=0; i<verticalCuts.size(); i++){
            maxHeight = max(maxHeight,(long int) verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        
        return (maxWidth * maxHeight) % int(1e9 + 7);
    }
};