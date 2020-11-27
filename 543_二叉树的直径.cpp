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
        int getDepth(TreeNode *root, int &res) {
                if (root == nullptr) {
                        return 0;
                }

                int leftDepth = getDepth(root->left, res);
                int rightDepth = getDepth(root->right, res);


                res = max(leftDepth+rightDepth, res);
                
                return max(leftDepth, rightDepth)+1;
        }

        int diameterOfBinaryTree(TreeNode* root)
        {
                int res = 0;
                cout << getDepth(root, res) << endl;
                return res;
        }
};
