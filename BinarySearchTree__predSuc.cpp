vector<Node*> findPreSuc(Node* root, int key){
    Node* pre = NULL;
    Node* suc = NULL;
    Node* curr = root;
    while(curr){
        if(curr->val < key){
            pred = curr;
            curr = curr->right;
        }
        else if(cuur->val > key){
            suc = curr;
            curr = curr->left;
        }
        else{
            if (cur->left) {
                Node* tmp = cur->left;
                while (tmp->right) tmp = tmp->right;
                pred = tmp;
            }
            if (cur->right) {
                Node* tmp = cur->right;
                while (tmp->left) tmp = tmp->left;
                succ = tmp;
            }
            break;
        }
    }
    return {pre,suc};
}