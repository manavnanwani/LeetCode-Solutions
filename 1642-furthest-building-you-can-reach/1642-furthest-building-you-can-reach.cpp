class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0, i=0;
        priority_queue<int> maxh;
        for(i=0; i<heights.size()-1; i++){
            int d = heights[i+1] - heights[i];
            if(d <= 0)
                continue;
            bricks -= d;
            maxh.push(d);
            
            if(bricks<0){
                bricks += maxh.top();
                maxh.pop();
                ladders--;
            }
            if(ladders<0)
                break;
        }
        return i;
    }
};