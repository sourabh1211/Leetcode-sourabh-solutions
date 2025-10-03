class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            dis[row][col] = steps;
            q.pop();
            int delr[]={0,1,0,-1};
            int delc[]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow = row+delr[i];
                int ncol = col+delc[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        return dis;
    }
};
