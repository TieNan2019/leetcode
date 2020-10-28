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
        int recursion(TreeNode *root) {
                if (root == NULL)
                        return 0;
                
                // 当前层没有偷窃 steal
                int steal = recursion(root->left) + recursion(root->right);

                // 当前层偷窃，跳过下一层直接偷向下数第二层 keep
                int keep = root->val;
                if (root->left) {
                        if (root->left->left)
                                keep += recursion(root->left->left);
                        if (root->left->right)
                                keep += recursion(root->left->right);
                }

                if (root->right) {
                        if (root->right->left)
                                keep += recursion(root->right->left);
                        if (root->right->right)
                                keep += recursion(root->right->right);
                }

                // 返回 steal 和 keep 的较大值
                return keep > steal ? keep : steal;
        }

        int rob(TreeNode* root) {
                return recursion(root);     
        }
};
