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
        vector<int> postorder(Node* root) {
                if (root == nullptr)
                        return {};
        
                vector<int> ans;

                Node *node = root;
                stack<Node *> s;
                s.push(root);
                stack<int> sidx;
                sidx.push(0);


                int cnt = 0;
                while (!s.empty()) {
                        if (cnt < s.top()->children.size()) {
                                node = s.top()->children[cnt];

                                s.push(node);
                                sidx.push(cnt);

                                cnt = 0;
                        }
                        else {
                                /* 后序遍历发生在此处 */
                                ans.push_back(s.top()->val);


                                s.pop();

                                cnt = sidx.top() + 1;
                                sidx.pop();
                        }
                }

                return ans;
        }
};
