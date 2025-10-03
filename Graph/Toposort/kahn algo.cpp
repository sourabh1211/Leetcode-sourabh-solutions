vector<int>toposort(int E,int V){
    vector<vector<int>>adj(V);
    for(auto i : E){
        int u = i.first;
        int v = i.second;
        adj[v].push_back(u);
    }
    queue<int>q;
    vector<int>indegree(V);
    for(int i=0;i<V;i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int node = q.top();
        q.pop();
        ans.push_back(node);
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    if ((int)ans.size() != V) return {};
    return ans;
}