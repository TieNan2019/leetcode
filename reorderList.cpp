#include <iostream>
#include <deque>
#include <vector>

using namespace std;



struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:

        void reorderList(ListNode* head) {
                if (head == nullptr)
                        return nullptr;

                // 另起一条链表
                deque<ListNode *> l;

                for (ListNode *node = head;
                node != nullptr;
                node = node->next)
                        l.push_back(node);

                bool flag = true;
                while (l.size() > 1) {
                        if (flag) {
                                l.front()->next = l.back();
                                l.pop_front();
                                flag = false;
                        }
                        else {
                                l.back()->next = l.front();
                                l.pop_back();
                                flag = true;
                        }
                }

                l.back()->next = nullptr;
                // l.pop_back();
        }
};


ListNode *insert(ListNode *head, int val) {
        ListNode *node = head;
        if (node == nullptr) {
                node = new ListNode(val);
                return node;
        }

        while (node->next != nullptr) {
                node = node->next;
        }
        node->next = new ListNode(val);

        return head;
}


ListNode *Init()
{
        ListNode *head;
        vector<int> data = {1, 2, 3, 4, 5, 6, 7};

        for (int x : data)
                head = insert(head, x);

        return head;
}

int main(void)
{
        ListNode *head = Init();

        Solution s;
        s.reorderList(head);

        for (ListNode *node = head; node != nullptr; node = node->next) {
                cout << node->val << " ";
        }

        cout << endl;


        return 0;
}
