vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(auto i : p){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
          }
        if (ans.size() != n)return {};
        return ans;
    }