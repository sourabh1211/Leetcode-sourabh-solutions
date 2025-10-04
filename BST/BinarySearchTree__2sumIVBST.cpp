class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        int low = 0;
        int high = ans.size() - 1;
        while (low < high) {
            int sum = ans[low] + ans[high];
            if (sum == k) {
                return true;
            } else if (sum > k) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
};
