int minValue(Node* root) {
        Node* curr = root;
        while(curr->left != NULL){curr = curr->left;}
        return curr->data;
        
    }
int maxValue(Node* root) {
        Node* curr = root;
        while(curr->right != NULL){curr = curr->right;}
        return curr->data;
        
    }