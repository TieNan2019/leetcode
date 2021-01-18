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

/* 通过适配器的方式满足特殊功能需求 */
struct Node {
public:
        TreeNode *parent;
        TreeNode *current;
        int pLayer;
        int count;

        Node(TreeNode *current, TreeNode *parent, int layer):
        current(current), parent(parent), pLayer(layer) {}
};


class Solution {
public:
        bool isCousins(TreeNode* root, int x, int y) {
                if (root->val == x || root->val == y)
                        return false;

                queue<Node> seq;
                
                seq.emplace(root, nullptr, 1);
                Node X(nullptr, nullptr, 0), Y(nullptr, nullptr, 0);

                int layer = 2;
                while (!seq.empty()) {
                        int len = seq.size();

                        for (int i = 0; i < len; i++) {
                                Node node = seq.front();
                                seq.pop();

                                if (node.current->left) {
                                        seq.emplace(node.current->left, node.current, layer);
                                        if (x == node.current->left->val)
                                                X = seq.back();
                                        if (y == node.current->left->val)
                                                Y = seq.back();
                                }

                                if (node.current->right) {
                                        seq.emplace(node.current->right, node.current, layer);
                                        if (x == node.current->right->val)
                                                X = seq.back();
                                        if (y == node.current->right->val)
                                                Y = seq.back();
                                }

                                if (X.current != nullptr && Y.current != nullptr)
                                        goto OUT;
                        }

                        layer++;
                }

                OUT:
                return (X.parent != Y.parent && X.pLayer == Y.pLayer);
        }
};
