vector<int>topview(root){
    vector<int>ans;
    if(root==NULL)reurn ans;
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        node* node = top.first;
        int line = top.second;
        if(mp.find(line)==mp.end()){
            mp[line]=node->val;
        }
        if(node->left){
            q.push({node->left,line-1});
        }
        if(node->right){
            q.push({node->right,line-1});
        }
    }
    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}
