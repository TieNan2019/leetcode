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
        int maxDepth(TreeNode* root) {
                if (root == NULL)
                        return 0;

                int left = 0, right = 0;
                if (root->left)
                        left = maxDepth(root->left);
                if (root->right)
                        right = maxDepth(root->right);

                // cout << left << endl;
                // cout << right << endl;

                return (left > right ? left : right) + 1;
        }
};
