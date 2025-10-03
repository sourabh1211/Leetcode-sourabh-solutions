bool toposort(int E,int V){
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
    int count = 0;
    while(!q.empty()){
        int node = q.top();
        q.pop();
        count++;
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    if (count == V) return false;
    return true;
}