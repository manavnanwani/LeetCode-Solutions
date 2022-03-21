class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size() - 1, ans = INT_MIN;
        while(l<r){
            ans = std::max((std::min(height[l], height[r])*(r-l)), ans);
            if(height[l]>=height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};