/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
        bool nextSection(Node *root) {
                if (root == NULL)
                        return false;

                Node *node = root;
                Node *frm = node->left;

                while (node) {
                        if (node->left) {
                                frm = node->left;
                                break;
                        }
                        else if (node->right) {
                                frm = node->right;
                                break;
                        }
                        node = node->next;
                }
                Node *visited = frm;

                while (node) {
                        if (node->left && visited != node->left) {
                                frm->next = node->left;
                                frm = node->left;
                                visited = node->left;
                        }

                        if (node->right && visited != node->right) {
                                frm->next = node->right;
                                frm = node->right;
                                visited = node->right;
                        }

                        node = node->next;
                }
                
                return false;
        }

        Node* connect(Node* root) {
                if (root == NULL)
                        return root;
                
                nextSection(root);

                Node *node = root;
                while (node) {
                        if (node->left) {
                                connect(node->left);
                                break;
                        }
                        else if (node->right) {
                                connect(node->right);
                                break;
                        }
                        node = node->next;
                }
                // connect(root->left);
                // connect(root->right);

                return root;
        }
};
