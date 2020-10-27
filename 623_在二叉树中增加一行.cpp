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
        TreeNode* addOneRow(TreeNode* root, int v, int d) {
                int depth = 1;
                queue<TreeNode *> seq;
                seq.push(root);

                if (d == 1) {
                        TreeNode *node = new TreeNode(v);
                        node->left = root;
                        return node;
                }

                while (!seq.empty()) {
                        depth++;

                        int levelSize = seq.size();

                        if (depth < d) {
                                for (int i = 0; i < levelSize; i++) {
                                        TreeNode *node = seq.front();
                                        seq.pop();


                                        if (node->left)
                                                seq.push(node->left);
                                        if (node->right)
                                                seq.push(node->right);

                                }
                        }
                        else {
                                for (int i = 0; i < levelSize; i++) {
                                        TreeNode *node = seq.front();
                                        seq.pop();

                                        if (node->left) {
                                                TreeNode *tmp = node->left;
                                                node->left = new TreeNode(v);
                                                node->left->left = tmp;
                                        }
                                        else
                                                node->left = new TreeNode(v);
                                
                                        if (node->right) {
                                                TreeNode *tmp = node->right;
                                                node->right = new TreeNode(v);
                                                node->right->right = tmp;
                                        }
                                        else
                                                node->right = new TreeNode(v);
                                }
                                // break;
                        }

                }

                return root;
        }
};
