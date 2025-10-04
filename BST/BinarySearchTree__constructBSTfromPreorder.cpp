TreeNode* pre(vector<int>&preorder,int minval,int maxval,int index){
    if(preorder.size() > index && prorder[index] > maxval || preorder[index] < minval){
        return nullptr;
    }
    int val = preorder[index];
     TreeNode* root = new TreeNode(val);
     index++;
     root->left = pre(preorder,minval,val,index);
     root->right = pre(preorder,val,maxval,index);
     return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder){
    int index = 0;
    return pre(preorder,INT_MIN,INT_MAX,index);
}