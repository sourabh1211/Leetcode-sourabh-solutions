class Solution {
public:
    TreeNode* minval(TreeNode* root){
        TreeNode* curr = root;
        while(curr->left != NULL){curr = curr->left;}
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return nullptr;
        if(root->val == key){
            if(root->left == NULL && root->right == NULL)return NULL;
            if(root->left != NULL && root->right == NULL){
                TreeNode* tmp = root->left;
                delete(root);
                return tmp;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* tmp = root->right;
                delete(root);
                return tmp;
            }
            if(root->left != NULL && root->right != NULL){
                TreeNode* tmp = minval(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right,tmp->val);
                return root;
            }
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};