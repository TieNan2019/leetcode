/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        int recursion(TreeNode* root) {
                // 如果是叶子节点
                if (root->left == nullptr
                && root->right == nullptr)
                        return 1;

                // 两支都存在
                if (root->left && root->right) {
                        int left, right;
                        left = recursion(root->left);
                        right = recursion(root->right);

                        return (left > right ? right : left) + 1;
                }
                // 存在右支
                else if (root->left == NULL) {
                        return 1 + recursion(root->right);
                }
                // 如果存在左枝
                else if (root->right == NULL) {
                        return 1 + recursion(root->left);
                }

                // 返回
                return 0;
        }

        int minDepth(TreeNode* root) {
                if (root == nullptr)
                        return 0;

                return recursion(root);
        }

};
