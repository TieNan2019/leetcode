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
        int depthDetect(TreeNode * root)
        {
                if (root == nullptr)
                        return 0;

                int leftDepth = 0, rightDepth = 0;

                leftDepth = depthDetect(root->left);
                rightDepth = depthDetect(root->right);

                if (leftDepth == -1)
                        return -1;
                if (rightDepth == -1)
                        return -1;

                // cout << "val : " << root->val << " left : "
                // << leftDepth << " right: " << rightDepth << endl;

                if (abs(leftDepth - rightDepth) > 1)
                        return -1;

                return leftDepth > rightDepth ?
                leftDepth + 1 : rightDepth + 1;
        }


        bool isBalanced(TreeNode* root) {
                if (depthDetect(root) == -1)
                        return false;
 
                return true;
        }
};
