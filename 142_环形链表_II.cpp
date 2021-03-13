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
        ListNode *detectCycle(ListNode *head) {
                ListNode *slower = head, *faster = head;

                while (faster) {
                        if (!faster->next || !faster->next->next)
                                return NULL;
                        
                        faster = faster->next->next;
                        slower = slower->next;

                        if (faster == slower)
                                break;
                }

                ListNode *ptr = head;

                while (ptr != slower) {
                        ptr = ptr->next;
                        slower = slower->next;
                }

                return ptr;
        }
};
