class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1, count = 0, m = grid.size(), n = grid[0].size();
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};

        queue<pair<int, int>> q;
        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    count++;
            }
        }
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
                pair<int, int> temp = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = temp.first + dx[i];
                    int ny = temp.second + dy[i];
                    if(nx >= 0  and ny >= 0 and nx < m and ny < n and grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        count--;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        if(count > 0) return -1;
        if(ans == -1) return 0;
        return ans;
    }
};