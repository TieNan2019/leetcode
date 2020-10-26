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
        vector<TreeNode *> buildTree (int from, int to)
        {
                if (from > to)
                        return {nullptr};

                if (from == to)
                        return {new TreeNode(to)};

                vector<TreeNode *> res;
                for (int rootIndex = from; rootIndex <= to; rootIndex++) {
                        vector<TreeNode *> leftChildren = buildTree(from, rootIndex-1);
                        vector<TreeNode *> rightChildren = buildTree(rootIndex+1, to);


                        // root->left = leftChildren;
                        // root->right = rightChildren;

                        for (auto l : leftChildren) {
                                for (auto r : rightChildren) {
                                        TreeNode *root = buildTree(rootIndex,rootIndex)[0];

                                        root->left = l;
                                        root->right = r;
                                        res.push_back(root);
                                }
                        }

                        // res.push_back(root);
                }

                return res;
        }

        vector<TreeNode*> generateTrees(int n) {
                if (n == 0)
                        return {};

                /* 后续动态规划用 */
                map<int, map<int, TreeNode*>> m;

                auto res = buildTree(1, n);


                return res;
        }
};
