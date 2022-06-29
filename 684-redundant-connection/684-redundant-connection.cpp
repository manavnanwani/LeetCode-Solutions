class Solution {
public:
    vector<int> graph;
    
    int find(int x){
        return graph[x]==x ? x : find(graph[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // int n = edges.size();
//         vector<int> vis(n+1, 0);
//         vector<int> ans;
//         vector<vector<int>> graph;
//         for(auto e:edges){
//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);

//         }
        
//         for(int i=0; i<n+1; i++){
//             if(!vis[i]){
//                 queue<pair<int, int>>q;
//                 q.push({i, -1});
//                 vis[i] = 1;
//                 while(!q.empty()){
//                     int node = q.front().first;
//                     int prev = q.front().second;
//                     q.pop();
                    
//                     for(auto it : graph[node]){
//                         if(vis[it] == 0){
//                             vis[it] = 1;
//                             q.push({it, node});
//                         }
//                         else if(prev != it){
//                             ans.push_back(it);
//                             ans.push_back(prev);                            
//                         }
//                     }
//                 }
//             }   
//         }
//         return ans;
        int n = edges.size();
        if(n == 0)
            return {};
        graph.resize(n + 1);
        for(int i=1; i<n+1; i++)
            graph[i] = i;
        
        for(auto e:edges){
            int f1 = find(e[0]);
            int f2 = find(e[1]);
            if(f1 != f2)
                graph[f1] = f2;
            else
                return e;
        }
        return {};
    }
};