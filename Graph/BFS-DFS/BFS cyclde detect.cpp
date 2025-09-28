#include<bits/stdc++.h>
using namespace std;
 bool bfs(vector<vector<int>>adj,vector<int>visited,int nde){
    queue<pair<int,int>>q;
    q.push({nde,-1});
    vis[node] = 1;
    while(!q.empty()){
        int node = q.top().first;
        int parent = q.top().second;
        q.pop();
        for(auto i :adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,node});
            }
            else if(i!=parent){
                return true;
            }
        }
    }
    return false;
 }




 