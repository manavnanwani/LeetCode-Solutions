class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int sourcecolor){
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        if(image[sr][sc] == color)
            return;
        image[sr][sc] = color;
        for(int i=0; i<4; i++){
            int nsr = sr + dx[i];
            int nsc = sc + dy[i];
            if(nsr >= 0 and nsc >= 0 and nsr < image.size() and nsc < image[0].size() and image[nsr][nsc] == sourcecolor)
                dfs(image, nsr, nsc, color, sourcecolor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};