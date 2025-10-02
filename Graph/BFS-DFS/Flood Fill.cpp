class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delr[i];
                int ncol = col + delc[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == originalColor) {
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};
