void in1(Node* root1,vector<int>&ans1){
    if(root==NULL)return;
    in(root->left,ans1);
    if(root != NULL)ans1.push_back(root->val);
    in(root->right,ans1);
}
void in1(Node* root2,vector<int>&ans2){
    if(root==NULL)return;
    in(root->left,ans2);
    if(root != NULL)ans2.push_back(root->val);
    in(root->right,ans2);
}
vector<int> merge(Node *root1, Node *root2) {
        vector<int>ans1;
        vector<int>ans2;
        in(root1,ans1);
        in(root2,ans2);
        ans1.insert(ans1.end(),ans2.begin(),ans2.end());
        sort(ans1.begin(),ans1.end());
        return ans1;
    }