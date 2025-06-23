// class Solution {
// public:
//     void in(TreeNode* root,vector<int>&ans){
//         if(root == NULL)return;
//         in(root->left,ans);
//         if(root != NULL){
//             ans.push_back(root->val);
//         }
//         in(root->right,ans);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>ans;
//         in(root,ans);
//         return ans[k-1];
//     }
// };
class Solution {
public:
    int count = 0;
    int result = -1;
    void inorder(TreeNode* root, int k) {
        if (!root) return;
        inorder(root->left, k);
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
