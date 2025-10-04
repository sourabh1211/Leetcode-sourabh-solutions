vector<int>level(TreeNode* root){
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    if(root==nullptr)return ans;
    q.push(root);
    bool lefttoright = true;
    while(!q.empty()){
        int len = q.size();
        vector<int>tmp;
        for(int i=0;i<len;i++){
        TreeNode* node = q.front();
        q.pop();
        tmp.push_back(node->val);
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
        }
        if(!lefttoright)reverse(tmp.begin(),tmp.end());
        ans.push_back(tmp);
        lefttoright = !lefttoright;
    }
    return ans;
}