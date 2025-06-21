class Solution {
public:
    void flatten(TreeNode* root) {
        // if (root == NULL) return;
        // stack<TreeNode*> st;
        // st.push(root);
        // while (!st.empty()) {
        //     TreeNode* curr = st.top();
        //     st.pop();
        //     if (curr->right) st.push(curr->right);
        //     if (curr->left) st.push(curr->left);
        //     if (!st.empty()) curr->right = st.top();
        //     curr->left = NULL;
        // }
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){prev = prev->right;}
                prev->right=curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
