int heigth(node* root){
    if(root == nullptr)return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right) + 1;
}