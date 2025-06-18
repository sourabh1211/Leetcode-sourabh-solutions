int maxsum(node* root){
    int maxsum = INT_MIN;
    solve(root,maxsum);
    return maxsum;
}
int solve(root,maxsum){
    if(root==nullptr)return 0;
    int left = max(0,solve(root->left,maxsum));
    int right = max(0,solve(root->right,maxsum));
    maxsum = max(maxsum,root->val+left+right);
    int ans = root->val + max(left,right);
    return ans;
}