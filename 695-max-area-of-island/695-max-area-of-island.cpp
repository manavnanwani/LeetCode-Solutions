class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y){
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        
        int count = 1;
        if(x < grid.size() and x>=0 and y < grid[0].size() and y>=0 and grid[x][y] == 1){
            for(int i=0; i<4; i++){
                grid[x][y] = 0;
                count += dfs(grid, x+dx[i], y+dy[i]);
            }   
            return count;
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};