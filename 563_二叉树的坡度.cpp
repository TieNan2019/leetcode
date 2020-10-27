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
        int childrenSum(TreeNode *root) {
                if (root == nullptr)
                        return 0;
                return root->val
                + childrenSum(root->left)
                + childrenSum(root->right);
        }

        int tilt(TreeNode *root) {
                if (root == nullptr)
                        return 0;
                // cout << root->val << " : " << childrenSum(root->left) <<
                // " " << childrenSum(root->right) << endl;
                return abs(childrenSum(root->left) - childrenSum(root->right));
        }


        int findTilt(TreeNode *root) {
                if (root == nullptr)
                        return 0;

                return tilt(root)
                + findTilt(root->left)
                + findTilt(root->right);
                // return tilt(root);
        }
};
