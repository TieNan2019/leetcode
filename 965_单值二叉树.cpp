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
        bool isUnivalTree(TreeNode* root) {
                bool cur = true;

                if (root->left == NULL && root->right == NULL)
                        return true;

                else if (root->left == NULL)
                        return (root->val == root->right->val) && isUnivalTree(root->right);
                
                else if (root->right == NULL)
                        return (root->val == root->left->val) && isUnivalTree(root->left);
                else 
                        return (root->val == root->left->val) && isUnivalTree(root->left)
                        && (root->val == root->right->val) && isUnivalTree(root->right);


                // cout << root->val << " : " << root->left->val << " " << root->right->val;

                return true; 
        }
};
