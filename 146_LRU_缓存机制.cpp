class LRUCache {
public:
        struct Node {
                Node *prev;
                Node *next;
                int key;
                int val;

                Node(int _key, int _val): 
                key(_key), val(_val), prev(nullptr), next(nullptr) {}
        };

        LRUCache(int _capacity) {
                capacity = _capacity;
        }

        void node2Head(Node *node) {
                /* 队头不做修改 */
                if (node == head)
                        return ;
                /* 原来在队尾 */
                else if (node == tail) {
                        tail = tail->prev;

                        if (tail)
                                tail->next = nullptr;

                        node->next = head;
                        if (head)
                                head->prev = node;
                        head = node;
                }
                else {
                        Node *prev = node->prev;
                        Node *next = node->next;

                        prev->next = next;
                        next->prev = prev;

                        node->next = head;
                        head->prev = node;
                        head = node;
                }
        }

        int get(int key) {
                if (nodeList.find(key) == nodeList.end())
                        return -1;
                
                /* 节点需要移动到队头 */
                Node *node = nodeList[key];
                node2Head(node);

                return head->val;
        }

        void put(int key, int value) {
                /* 节点不存在，则添加到队头 */
                if (nodeList.find(key) == nodeList.end()) {
                        Node *node = new Node(key, value);
                        node->next = head;

                        if (nodeList.empty())
                                tail = node;
                        else
                                head->prev = node;

                        head = node;

                        nodeList[key] = head;

                        /* 如果大于容量，则需要删除队尾 */
                        if (nodeList.size() > capacity) {
                                node = tail;

                                tail = tail->prev;
                                tail->next = nullptr;

                                nodeList.erase(node->key);
                                delete node;
                        }
                }
                /* 节点存在，并移动到队头 */
                else {
                        Node *node = nodeList[key];
                        node2Head(node);

                        head->val = value;
                }
        }

        int capacity = 0;
        Node *head = nullptr;
        Node *tail = nullptr;
        map<int, Node *> nodeList;
        unsigned int elapse = 0;
};
