int solve(root,diameter){
    if(root==NULL)return 0;
    int left = solve(root->left,diameter);
    int right = solve(root->right,diameter);
    int diameter = max(diameter,left+right);
    int ans =  + max(left,right);
    return ans;
}
int dia(root){
    int diameter = 0;
    solve(root,diameter);
    return diameter;
}