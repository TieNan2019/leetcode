class Solution {
public:
        int countBinarySubstrings(string s) {
                int count = 0;

                for (int h = 0; h < s.size()-1; h++) {
                        int t = h + 1;

                        // cout << "Line : " << h << endl;

                        if (s[h] != s[t]) {
                                int head = h, tail = t;
                                count++;

                                while (head-1 >= 0 && tail+1 < s.size()) {
                                        // cout << head << ", " << tail << endl;

                                        head--; tail++;
                                        if (s[head] == s[head+1] && s[tail] == s[tail-1])
                                                count++;
                                        else
                                                break;
                                }
                        }

                }

                return count;
        }
};
