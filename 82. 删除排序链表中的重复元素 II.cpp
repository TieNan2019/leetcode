/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
        ListNode* deleteDuplicates(ListNode* head) {
                ListNode *fakeHead = new ListNode(INT_MIN);
                fakeHead->next = head;

                for (ListNode *slower = fakeHead; slower->next != nullptr; ) {
                        ListNode *probe = slower->next;

                        if (probe->next && probe->val == probe->next->val) {
                                int val = probe->val;

                                while (probe->next && probe->next->val == val)
                                        probe = probe->next;
                                
                                /* 截断相同数字链表的头 */
                                ListNode *toDel = slower->next;
                                /* 链表直接跨过重复元素 */
                                slower->next = probe->next;
                                /* 截断相同数字子链的尾 */
                                probe->next = nullptr;

                                /* 删除重复的子节点 */
                                while (toDel) {
                                        ListNode *tmp = toDel;
                                        toDel = toDel->next;
                                        delete tmp;
                                }
                        }
                        else
                                slower = slower->next;
                }

                head = fakeHead->next;
                delete fakeHead;

                return head;
        }
};
