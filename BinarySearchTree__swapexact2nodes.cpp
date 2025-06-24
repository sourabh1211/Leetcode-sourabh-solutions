class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i]->val < nodes[i - 1]->val) {
                if (!first) first = nodes[i - 1];
                second = nodes[i];
            }
        }
        if (first && second) swap(first->val, second->val);
    }
};
