/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
        vector<int> preorder(Node* root) {
                if (root == nullptr)
                        return {};
        
                vector<int> ans;

                Node *node = root;
                stack<Node *> s;
                s.push(root);
                stack<int> sidx;
                sidx.push(0);
            
                /* 首先要在这里处理根节点 */
                ans.push_back(root->val);


                int cnt = 0;
                while (!s.empty()) {
                        if (cnt < s.top()->children.size()) {
                                node = s.top()->children[cnt];

                                /* 先序遍历发生在此处 */
                                ans.push_back(node->val);

                                s.push(node);
                                sidx.push(cnt);

                                cnt = 0;
                        }
                        else {
                                s.pop();

                                cnt = sidx.top() + 1;
                                sidx.pop();
                        }
                }

                return ans;
        }
};
