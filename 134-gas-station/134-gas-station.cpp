class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = accumulate(gas.begin(), gas.end(), 0);
        int totalcost = accumulate(cost.begin(), cost.end(), 0);
    
        if(totalgas < totalcost)
            return -1;
        
        int curr = 0, start = 0;
        for(int i=0; i<cost.size(); i++){
            if(curr < 0){
                start = i;
                curr = 0;
            }
            curr += (gas[i] - cost[i]);
        }
        return start;
    }
};