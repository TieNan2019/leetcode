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
        bool isPalindrome(ListNode* head) {
                stack<int> s;

                int len = 0;
                for (ListNode *node = head; node != NULL; node = node->next)
                        len++;
                
                int i = 0;
                ListNode *node;
                for (node = head, i = 1; node != NULL; node = node->next, i++) {
                        if (len % 2 &&i == (int)((float)len / 2 + 0.5))
                                continue;
                        else if (i <= (float)len / 2) {
                                s.push(node->val);
                        }
                        else if (i * 2 > ((float)len / 2)) {
                                if (node->val != s.top())
                                        return false;
                                else
                                        s.pop();
                        }
                }


                return s.empty();
        }
};
