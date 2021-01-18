class Solution {
public:
        vector<int> diStringMatch(string S) {
                vector<int> values;

                deque<int> nums;
                for (int i = 0; i <= S.size(); i++)
                        nums.push_back(i);
                

                if (S.front() == 'I') {
                        values.push_back(nums.front());
                        nums.pop_front();
                }
                else {
                        values.push_back(nums.back());
                        nums.pop_back();
                }

                for (int i = 0; i < S.size() - 1; i++) {
                        char ch = S[i];
                        char next = S[i+1];
                        if (ch == 'I' && next == 'I') {
                                values.push_back(nums.front());
                                nums.pop_front();
                        }
                        else if (ch == 'I' && next == 'D') {
                                values.push_back(nums.back());
                                nums.pop_back();
                        }
                        else if (ch == 'D' && next == 'D') {
                                values.push_back(nums.back());
                                nums.pop_back();
                        }
                        else if (ch == 'D' && next == 'I') {
                                values.push_back(nums.front());
                                nums.pop_front();
                        }
                }

                values.push_back(nums.front());

                return values;
        }
};
