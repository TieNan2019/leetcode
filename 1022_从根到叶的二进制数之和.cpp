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

        int sumRootToLeaf(TreeNode* root) {
                int sum = 0;

                TreeNode *node = root, *visited = nullptr;
                vector<TreeNode *> s;

                while (node || !s.empty()) {
                        if (node) {//走到最左边
                                s.push_back(node);
                                node = node->left;
                        }
                        else {
                                node = s.back();

                                //右子树存在，未被访问
                                if (node->right && node->right != visited)
                                        node = node->right;
                                else {
                                        s.pop_back();

                                        if (node->left == nullptr && node->right == nullptr) {
                                                int num = 0;
                                                for (TreeNode *p : s)
                                                        num = (num << 1) + p->val;
                                                sum += (num << 1) + node->val;
                                        }
                                        

                                        visited = node;                         //记录最近访问过的节点
                                        node = nullptr;                         //节点访问完后，重置p指针
                                }
                        }//else
                }//while

                return sum;
        }
};
