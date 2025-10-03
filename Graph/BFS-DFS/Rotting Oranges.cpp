class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    q.push({0,{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int tm = q.front().first;
            int row = q.front().second.first;
            int col= q.front().second.second;
            time = max(time,tm);
            q.pop();
            int delr[]={1,0,-1,0};
            int delc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow = row + delr[i];
                int ncol = col + delc[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({tm+1,{nrow,ncol}});
                    grid[nrow][ncol] = 2;
                    vis[nrow][ncol] = true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};
