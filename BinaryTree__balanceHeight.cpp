int heigth(node* root){
    if(root==NULL)return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right) + 1;
}
bool balance(node* root){
     if(root==NULL)return true;
     int left = heigth(root->left;)
      int right = height(root->right);
      if(abs(left-right) > 1)return false;
      return balance(root->left) && balance(root->right);
}