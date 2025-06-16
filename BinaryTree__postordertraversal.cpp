class Solution {
public:
    void post(TreeNode* root,vector<int>&ans){
        if(root==nullptr)return;
        post(root->left,ans);
        post(root->right,ans);
        if(root!=NULL)ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        post(root,ans);
        return ans;
    }
};