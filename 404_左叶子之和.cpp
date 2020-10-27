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
        int sum;
        int recursion(TreeNode *root, bool onLeft) {
                if (root == NULL)
                        return 0;

                int thisVal = 0;
                if (root->left == NULL
                && root->right == NULL
                && onLeft) {
                        thisVal = root->val;
                }

                return thisVal + recursion(root->left, true)
                + recursion(root->right, false);
        }
        int sumOfLeftLeaves(TreeNode* root) {
                return recursion(root, false);
        }
};
