class Solution {
public:
    TreeNode* solve(vector<int>& inorder, int instart, int inend,vector<int>& postorder, int poststart, int postend) {
        if (poststart > postend || instart > inend)return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inorderindex = instart;
        while (inorder[inorderindex] != root->val && inorderindex <= inend) {
            inorderindex++;
        }
        int leftsize = inorderindex - instart;
        root->left = solve(inorder, instart, inorderindex - 1, postorder,poststart, poststart + leftsize - 1);
        root->right = solve(inorder, inorderindex + 1, inend, postorder,poststart + leftsize, postend - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return solve(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};
