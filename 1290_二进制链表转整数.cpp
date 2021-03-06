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
        int getDecimalValue(ListNode* head) {
                int ans = 0;

                ListNode *node = head;

                for (node = head; node != NULL; node = node->next)
                        ans = (ans << 1) + node->val;

                return ans;
        }
};
