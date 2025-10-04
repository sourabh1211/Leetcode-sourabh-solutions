struct Node {
    int val;
    Node* left;
    Node* right;
};

void leftBoundary(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    ans.push_back(root->val);
    if (root->left) leftBoundary(root->left, ans);
    else leftBoundary(root->right, ans);
}

void rightBoundary(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    if (root->right) rightBoundary(root->right, ans);
    else rightBoundary(root->left, ans);
    ans.push_back(root->val);
}

void leaves(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->val);
        return;
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    ans.push_back(root->val);
    leftBoundary(root->left, ans);
    leaves(root->left, ans);
    leaves(root->right, ans);
    rightBoundary(root->right, ans);
    return ans;
}
