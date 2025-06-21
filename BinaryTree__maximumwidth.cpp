int MaximumWidth(TreeNode* root){
    int ans = 0;
    if(root==NULL)return 0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int len = q.size();
        int maxindex = q.front().second;
        int first = 0;
        int last = 0;
        for(int i=0;i<len;i++){
            auto top = q.front();
            q.pop();
            TreeNode* node = top.first;
            int index = top.second - maxindex;;
            if(i==0)first = index;
            if(i==len-1)last = index;
            if(node->left){
                q.push({node->left,2*index+1});
            }
            if(node->right){
                q.push({node->right,2*index+2});
            }
        }
        ans = max(ans,last-first+1);
    }
    return ans;
}