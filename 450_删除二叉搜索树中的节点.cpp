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
        TreeNode* deleteNode(TreeNode* root, int key) {
                if (root == nullptr)
                        return root;

                // 小于当前点搜素左枝
                if (key < root->val)
                        root->left = deleteNode(root->left, key);
                // 大于当前根节点搜索右支
                else if (key > root->val)
                        root->right = deleteNode(root->right, key);
                else {
                        // cout << root->val << endl;
                        if (root->left == NULL
                        && root->right == NULL) {
                                delete root;
                                return nullptr;
                        }
                        // 只有右子树
                        else if (root->left == NULL) {
                                // 找到右子树最小节点
                                TreeNode * node;
                                for (node = root->right; node->left; node = node->left);

                                // 当前节点值设为最小值
                                root->val = node->val;

                                // 递归删除临时节点
                                root->right = deleteNode(root->right, node->val);
                        }
                        // 有左子树
                        else {
                                // 找到左子树中最大点节点
                                TreeNode *node;
                                for (node = root->left; node->right; node = node->right);

                                // 当前节点值设为最大值
                                root->val = node->val;

                                // 递归删除 临时节点
                                root->left = deleteNode(root->left, node->val);
                        }
                }

                return root;
        }
};
