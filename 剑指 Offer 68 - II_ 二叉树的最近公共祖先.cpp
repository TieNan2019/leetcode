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
        TreeNode *pNode;

        bool recursion(TreeNode *root, const TreeNode* p, const TreeNode *q) {
                if (root == NULL)
                        return root;
                
                bool lret = recursion(root->left, p, q);
                bool rret = recursion(root->right, p, q);
                
                /* 后序遍历 */
                if (pNode == NULL /* 父节点还没有被找到的时候才会进行判断，因为要求找到最小父节点 */
                && ((lret && rret) /* 左右子节点都已经返回 */ 
                || ((lret || rret) && (root == p || root == q)) /* 或者已经找到其中一个子节点, 且当前节点是另一个目标节点 */
                ))
                        pNode = root;

                /* 发现当前节点时，返回非空，向当前节点的父节点报告 */
                return (root == p || root == q)
                /* 如果某一个子节点是目标节点，则继续向上报告 */
                /* 如果当前节点并非目标节点，且子节点也不存在目标节点，则返回空告诉上层节点 */
                || lret || rret;
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                pNode = NULL;
                recursion(root, p, q);

                return pNode;
        }
};
