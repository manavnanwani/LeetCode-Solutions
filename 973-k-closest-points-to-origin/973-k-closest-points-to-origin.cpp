class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>> q;
        for(int i=0; i<points.size(); i++){
            q.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]),points[i]});
            if(q.size() > k)
                q.pop();
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};