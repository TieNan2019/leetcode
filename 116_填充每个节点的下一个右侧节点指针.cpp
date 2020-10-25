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
        int recursion(Node *root, int leftFlag = true) {
                if (root == NULL)
                        return 0;

                /* 如果存在父节点 */
                if (root->next != NULL) {
                        /* 左侧节点指向右侧节点 */
                        if (leftFlag) {
                                /* 先指向父节点点右子节点 */
                                root->next = root->next->right;

                        }
                        /* 右侧节点与父节点右侧节点左子节点相连 */
                        else {
                                /* 如果父节点右右侧节点 */
                                if (root->next->next)
                                        root->next = root->next->next->left;
                                else
                                        root->next = NULL;
                        }
                }


                /* 左枝 */
                if (root->left) {
                        /* 先告诉它存在父节点 */
                        root->left->next = root;
                        recursion(root->left, true);
                }

                /* 右支 */
                if (root->right) {
                        /* 告诉它存在父节点 */
                        root->right->next = root;
                        recursion(root->right, false);
                }

                return 0;
        }

        Node* connect(Node *root) {
                recursion(root);

                return root;
        }
};
