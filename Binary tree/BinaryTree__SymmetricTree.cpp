bool symmetry(root p,root q){
    if(p==NULL && q==NULL)return true;
    if(p==NULL || q==NULL)return false;
    if(p->val != q->val)return false;
    return symmetry(p->left,q->right) && symmetry(p->right,q->left);
}
bool isSymmetric(root){
 if(root == NULL) return true;
    return isSymmetri(root->left, root->right);
    }