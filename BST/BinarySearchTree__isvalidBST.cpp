class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN, LLONG_MAX);
    }
    bool solve(TreeNode* root,long long minval,long long maxval){
        if(root == nullptr)return true;
        if(root->val >= maxval || root->val <= minval)return false;
        return solve(root->left,minval,root->val) && solve(root->right,root->val,maxval);
    }
};