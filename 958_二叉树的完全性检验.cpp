/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        bool isCompleteTree(TreeNode* root) {
                /* 层次遍历 */
                queue<TreeNode *> seq;
                seq.push(root);

                while (!seq.empty()) {
                        TreeNode *node = seq.front();
                        seq.pop();

                        /* 如果到达空节点, 且队列非空, 则不具备完全性 */
                        if (node == NULL) {
                                while (!seq.empty()) {
                                        TreeNode *n = seq.front();
                                        seq.pop();
                                        if (n != NULL)
                                                return false;
                                }
                                break;
                        }

                        /* 入队之前不进行空节点判断 */
                        seq.push(node->left);
                        seq.push(node->right);


                }

                return true;
        }
};
