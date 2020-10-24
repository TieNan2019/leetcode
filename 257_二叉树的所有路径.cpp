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
        vector<vector<int>> getPath(TreeNode *root)
        {
                if (root == NULL)
                        return {};

                /* 此题很关键的一点, 一定要到达叶子结点 */
                if (root->left == NULL && root->right == NULL)
                        return {{root->val}};

                /* 遍历路径 */
                vector<vector<int>> left = getPath(root->left);
                vector<vector<int>> right = getPath(root->right);


                /* 将路径汇总后返回 */
                vector<vector<int>> res;

                for (vector<int> v : left) {
                        v.insert(v.begin(), root->val);
                        res.push_back(v);
                }
                for (vector<int> v : right) {
                        v.insert(v.begin(), root->val);
                        res.push_back(v);
                }

                return res;
        }

        vector<string> binaryTreePaths(TreeNode* root) {
                auto seq = getPath(root);
                vector<string> res;

                /* 批量转换成字符串 ---- 直接在递归里转换代码是在太丑了😭 */
                for (auto v : seq) {
                        if (!v.empty()) {
                                string s = to_string(v[0]);
                                for (int i = 1; i < v.size(); i++)
                                        s = s + ("->" +  to_string(v[i]));
                                res.push_back(s);
                        }
                }

                return res;
        }
};
