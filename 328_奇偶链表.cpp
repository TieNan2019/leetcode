class Solution {
public:
        ListNode* oddEvenList(ListNode* head) {
                /* save a new chain to save the even nodes */
                ListNode *even = nullptr, *insert;

                ListNode *p = head;

                // cout << head->val << endl;
                
                while (p != nullptr) {

                        if (p->next != nullptr) {
                                if (even == nullptr) {
                                        // cout << "create head : " << p->next->val << endl;

                                        even = p->next;
                                        insert = even;

                                        p->next = p->next->next;

                                        insert->next = nullptr;
                                }
                                else {
                                        // cout << "add tail : " << p->next->val << endl;

                                        insert->next = p->next;

                                        insert = insert->next;
                                        p->next = insert->next;

                                        insert->next = nullptr;
                                }
                        }

                        // if (p->next)
                        p = p->next;

                }
                
		ListNode *ptr;
                for (ptr = head; ptr; ptr = ptr->next) {
			if (ptr->next == nullptr)
				break;
                }
                if (even)
		        ptr->next = even;

                return head;
        }
};
