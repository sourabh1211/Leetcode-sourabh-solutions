class Codec {
public:
   string serialize(TreeNode* root) {
    if (!root) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            s += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            s += "#,";
        }
    }
    return s;
}


    TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;
    vector<string> vals;
    string temp = "";
    for (char ch : data) {
        if (ch == ',') {
            vals.push_back(temp);
            temp = "";
        } else {
            temp += ch;
        }
    }
    TreeNode* root = new TreeNode(stoi(vals[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < vals.size() && vals[i] != "#") {
            node->left = new TreeNode(stoi(vals[i]));
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != "#") {
            node->right = new TreeNode(stoi(vals[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}
};