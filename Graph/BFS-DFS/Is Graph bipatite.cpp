class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int>& color, int colour, int node) {
        vis[node] = 1;
        color[node] = colour;
        for (auto i : graph[node]) {
            if (!vis[i]) {
                if (!dfs(graph, vis, color, !colour, i)) return false;
            } else if (color[i] == colour) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> color(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(graph, vis, color, 0, i)) return false;
            }
        }
        return true;
    }
};  