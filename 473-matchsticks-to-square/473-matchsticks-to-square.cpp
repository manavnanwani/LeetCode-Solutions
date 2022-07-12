class Solution {
public:
    bool makesquare(vector<int>& ms) {
        int sum = 0;
        sum = accumulate(ms.begin(), ms.end(), sum);
        if(ms.size() < 4 || sum % 4)
            return false;
        vector<int> visited(ms.size(), false);
        return calc(ms, visited, sum / 4, 0, 0, 4);
    }
    
    bool calc(vector<int> &ms, vector<int> &vs, int target, int curr, int i, int j){
        if(j == 1)
            return true;
        if(curr == target)
            return calc(ms, vs, target, 0, 0, j-1);
        for(int k = i; k < ms.size(); k++){
            if(vs[k] || ms[k] + curr > target)
                continue;
            
            vs[k] = true;
            if(calc(ms, vs, target, curr + ms[k], k+1, j)) return true;
            vs[k] = false;
        }
        return false;
    }
};