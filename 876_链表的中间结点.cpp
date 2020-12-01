/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
        ListNode* middleNode(ListNode* head) {
                ListNode *slower = head, *faster = head;

                while (faster && faster->next) {
                        faster = faster->next->next;

                        slower = slower->next;

                        if (faster == nullptr || faster->next == nullptr)
                                return slower;
                }

                return slower;
        }
};
