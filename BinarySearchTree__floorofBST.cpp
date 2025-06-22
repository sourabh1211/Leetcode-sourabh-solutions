int floor(Node* root, int x) {
        int val = -1;
        Node* curr = root;
        while(curr != nullptr){
            if(curr->data == x)return curr->data;
            if(curr->data < x){
                val = curr->data;
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        return val;
    }