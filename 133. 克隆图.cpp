/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
        Node *recursion(Node *node, map<Node *, Node *> &nmap) {
                /* 遍历相邻节点 */
                for (int i = 0; i < node->neighbors.size(); i++) {
                        Node *ptr = node->neighbors[i];

                        /* 如果当前指向的节点未被映射 */
                        if (nmap.find(ptr) == nmap.end()) {
                                /* 拷贝节点 */
                                Node *p = new Node(node->neighbors[i]->val, node->neighbors[i]->neighbors);

                                /* 建立映射并深度递归 */
                                nmap[ptr] = p;
                                node->neighbors[i] = nmap[ptr];
                                node->neighbors[i] = recursion(node->neighbors[i], nmap);
                        }
                        /* 已经存在对应旧节点的拷贝 */
                        else {
                                /* 创建节点的时候已经进行过递归拷贝，此时只需要修改指针即可 */
                                node->neighbors[i] = nmap[ptr];
                        }

                }

                return node;
        }

        Node* cloneGraph(Node* node) {
                if (node == nullptr)
                        return nullptr;

                /* 将原图的地址映射向新图 */
                map<Node *, Node *> nmap;

                /* 创建新图的起始节点 */
                Node *ans = new Node(node->val, node->neighbors);
                nmap[node] = ans;

                /* 深度优先递归 */
                return recursion(ans, nmap);
        }
};
