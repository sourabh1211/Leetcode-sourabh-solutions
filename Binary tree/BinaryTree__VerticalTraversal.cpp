vector<vector<int>>verticalTraversal(root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    map<int,map<int,multiset<int>>>mp;
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,0,0});
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        TreeNode* node = top.first;
        int x = top.second.first;
        int y = top.second.second;
        mp[x][y].insert(node->val);
        if(node->left){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            q.push({node->right,{x+1,y+1}});
        }
    }
    for(auto i : mp){
        vector<int>tmp;
        for(auto j : i.second){
            tmp.insert(tmp.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(tmp);
    }
return ans;
}