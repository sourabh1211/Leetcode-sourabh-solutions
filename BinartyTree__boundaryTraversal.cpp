void leftboundary(root,vector<int>&ans){
    if(root==null || root->left==NULL ||root->right==NULL)return;
    ans.push_back(root->val);
    if(root->left != NULL)leftboundary(root->left,ans);
    else leftboundary(root->right,ans);
}
void rightboundary(root,vector<int>&ans){
    if(root==null || root->left==NULL ||root->right==NULL)return;
    if(root->right != NULL)rightboundary(root->right,ans);
    else rightboundary(root->left,ans);
    ans.push_back(root->val);
}
void leavesnode(root,vector<int>&ans){
    if(root==NULL)return;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->val);
        return;
    }
    leavesnode(root->left,ans);
    leavesnode(root->right,ans)
}
vector<int>boundarytraversal(root){
    vector<int>ans;
    if(root==NULL)return ans;
    ans.push_back(root->val);
    leftboundary(root->left,ans);
    leaves(root->left,ans);
    leaves(root->right,ans);
    rightboundary(root->right,ans);

}