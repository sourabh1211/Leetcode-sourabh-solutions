int ceilofbst(root,x){
    int val = -1;
    node* curr = root;
    if(curr->data == x)return curr->data;
    if(curr->data > x){
        val = curr->data;
        curr=  curr->left;
    }
    else curr = curr->right;
    return val; 

}