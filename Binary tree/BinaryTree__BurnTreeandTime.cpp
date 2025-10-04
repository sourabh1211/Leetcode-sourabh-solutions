class Solution {
public:
    void baaphumai(TreeNode* root,TreeNode* &strt, int start,unordered_map<TreeNode* , TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            if(node->val == start)strt = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
             if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        TreeNode* strt = new TreeNode(start);
        unordered_map<TreeNode*,TreeNode*>parent;
        baaphumai(root,strt,start,parent);
        queue<pair<TreeNode*,int>>q;
        unordered_map<TreeNode*,bool>vis;
        q.push({strt,0});
        vis[strt] = true;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int dis = q.front().second;
            q.pop();
            ans = max(ans,dis);
            if(node->left && !vis[node->left]){
                q.push({node->left,dis+1});
                vis[node->left] = true;
            }
            if(node->right && !vis[node->right]){
                q.push({node->right,dis+1});
                vis[node->right] = true;
            }
            if(parent.count(node) && !vis[parent[node]]){
                q.push({parent[node],dis+1});
                vis[parent[node]] = true;
            }
        }
        return ans;
    }
};