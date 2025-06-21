class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            TreeNode* node = top.first;
            int level = top.second;
            if(mp.find(level)==mp.end()){
            mp[level]=node->val;
        }
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};