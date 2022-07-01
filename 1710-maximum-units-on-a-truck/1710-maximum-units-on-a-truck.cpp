class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0, step = 0;
        for(auto i:boxTypes){
            for(int j=0; j<i[0]; j++){
                if(step == truckSize)
                    break;
                ans += i[1];
                step++;
            }
            if(step == truckSize)
                break;
        }
        return ans;
    }
};