bool dfs(adj,vis,node,parent){
    vis[node]=1;
    for(auto i : adj[node]){
        if(!vis[node]){
            if(dfs(adj,vis,i,node)==true)return true;
            else if(i!=parent)return true;
        }
    }
  return false;
}
 bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }

};
