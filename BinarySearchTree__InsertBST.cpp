TreeNode* insert(root,x){
    TreeNode* curr = root;
    if(root==NULL)return new TreeNode*(x);
    while(curr != NULL){
        if(curr->data <= val){
            if(curr->right != NULL){
                curr = curr->right;
            }else{
                curr->right = new TreeNode(x);
                break;
            }
        }
        else{
             if(curr->left != NULL){
                curr = curr->left;
            }else{
                curr->left = new TreeNode(x);
                break;
            }
        }
    }
    return root;
}