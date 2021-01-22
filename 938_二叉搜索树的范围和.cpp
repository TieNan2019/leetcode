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
        int rangeSumBST(TreeNode* root, int low, int high) {

                vector<TreeNode *> s;
                TreeNode *node = root, *visited = nullptr;

                int sum = 0;

                while (node || !s.empty()) {
                        while (node) {
                                s.push_back(node);

                                if (node->val >= low)
                                        node = node->left;
                                else
                                        node = nullptr;
                        }

                        node = s.back();
                        if (node->right && node->right != visited && node->val <= high)
                                node = node->right;
                        else {
                                if (node->val <= high && node->val >= low)
                                        sum += node->val;

                                s.pop_back();

                                visited = node;
                                node = nullptr;
                        }
                }

                return sum;
        }
};
