class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int node){
        vis[node]=1;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(adj,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        if(a[i][j] == 1 && i != j){
            adj[i].push_back(j);
        }
    }
}
        int count = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);count++;
            }
        }
        return count;
    }

};
