class Solution {
public:
        Node* connect(Node* root) {
                if (root == NULL)
                        return NULL;
                
                if (root->left && root->right)
                        root->left->next = root->right;
                
                if (root->next && root->right)
                        root->right->next = root->next->left;
                
                connect(root->left);
                connect(root->right);

                return root;
        }
};
