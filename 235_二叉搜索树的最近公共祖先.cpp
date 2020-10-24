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
        TreeNode *traverse(TreeNode * root, 
        TreeNode *p, TreeNode *q) {
                if (root == NULL)
                        return NULL;

                // 两个值全部在左枝
                if (root->val > p->val
                && root->val > q->val)
                        return traverse(root->left, p, q);

                // 两个值全部在右枝
                else if (root->val < p->val
                && root->val < q->val)
                        return traverse(root->right, p, q);

                // 如果不再同一个分支, 则返回当前节点
                return root;
        }


        TreeNode* lowestCommonAncestor(
        TreeNode* root, TreeNode* p, TreeNode* q)
        {
                return traverse(root, p, q);
        }
};
