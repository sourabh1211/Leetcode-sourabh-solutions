vector<string>roottoleaf(TreeNode* root){
    vector<string>ans;
    if(root==nullptr)return ans;
    string path;
    dfs(root,path,ans);
    return ans;
}
void dfs(TreeNode* root,string path,vector<string>&ans){
      if(root==NULL)return;
      if(!path.empty()){
        path += "->";
      }
      if(root->left == NULL && root->right == NULL){
        ans.push_back(path);
        return;
      }
      if(root->left)dfs(root->left,path,ans);
      if(root->right)dfs(root->right,path,ans);
}