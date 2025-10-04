void baaphumai(Node* root,unordered<Node*,Node*>&parent){
    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
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
vector<int>NodeKDis(Node* root){
    vector<int>ans;
  unordered<Node*,Node*>parent;
  baaphumai(root,parent);
  queue<pair<Node*,int>>q;
  unordered_map<Node*,int>vis;
  q.push({root,0});
  while(!q.empty()){
    Node* node = q.front().first;
    int dis = q.front().second;
    q.pop();
    if(dis==k)ans.push_back(node->val);
    if(dis > k)break;
    if(node->left && !vis[node->left]){
        q.push({node->left,dis+1});
        vis[node->left]=true;
    }
    if(node->right && !vis[node->right]){
        q.push({node->right,dis+1});
        vis[node->right]=true;
    }
    if(parent.count(node) && !vis[parent[node]]){
        q.push({parent[node],dist+1});
        vis[parent[node]] = true;
    }
  }
  return ans;
}