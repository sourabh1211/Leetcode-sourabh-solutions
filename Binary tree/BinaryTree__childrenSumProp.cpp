int isSumProperty(Node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return 1;
    int leftVal = (root->left) ? root->left->data : 0;
    int rightVal = (root->right) ? root->right->data : 0;
    if(root->data == leftVal + rightVal && isSumProperty(root->left) && isSumProperty(root->right)) return 1;
    else return 0;