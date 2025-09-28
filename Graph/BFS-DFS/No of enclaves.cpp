class Solution {
public: 
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col){
        int n = grid.size(),m=grid[0].size();
        int delr[]={1,-1,0,0};
        int delc[]={0,0,1,-1};
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow = row+delr[i];
            int ncol = col+delc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid){
         int n = grid.size(),m=grid[0].size();
         int count = 0;
         vector<vector<int>>visited(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                dfs(grid, visited, i, 0);
            }
            if (!visited[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(grid, visited, i, m - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && grid[0][i] == 1) {
                dfs(grid, visited,0, i);
            }
            if (!visited[n - 1][i] && grid[n - 1][i] == 1) {
                dfs(grid, visited,n - 1, i);
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
         }
         return count;
    }
};