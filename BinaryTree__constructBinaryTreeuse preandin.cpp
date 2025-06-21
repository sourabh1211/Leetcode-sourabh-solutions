TreeNode* solve(vector<int>preorder,vector<int>inorder,int pstart,int pend,int instart, int inend){
    if(pstart > pend || instart > inend)return NULL;
    TreeNode* root = new TreeNode(preorder[pstart]);
    int inorderindex = instart;
    while(inorder[inorderindex] != root->val && instart <= inend){
        inorderindex++;
    }
    int leftpart = inorderindex - instart;
    root->left = solve(preorder,inorder,pstart,pstart+leftpart,instart,inorderindex - 1);
    root->right = solve(preorder,inorder,pstart+leftpart+1,pend,inorderindex + 1,inend);
    return root;
}
vectorTreeNode*>constructTree(vector<int>preorder,vector<int>inorder){
    int n = preorder.size();
    return solve(preorder,inorder,0,n-1,0,n-1);
}