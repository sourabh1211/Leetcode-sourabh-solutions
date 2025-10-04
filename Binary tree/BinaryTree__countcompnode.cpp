class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        inorder(root->left,ans);
        if(root != NULL)ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans.size();
    }
};