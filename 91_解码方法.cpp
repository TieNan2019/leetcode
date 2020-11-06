class Solution {
public:
        map<int, int> rec;
        int numDecodings(string s) {
                if (s.empty())
                        return 1;

                int total = 0;

                if (rec.find(s.size()) != rec.end()) {
                        total = rec[s.size()];
                }
                else {
                        /* 取一个长度 */
                        /* 非 0 检验 */
                        if (s[0] != '0') {
                                total += numDecodings(s.substr(1));

                                /* 取两个长度 */
                                if (s.size() >= 2) {
                                        int x = (s[0] - '0') * 10 + (s[1] - '0');

                                        /* 大于 0 小于 27 */
                                        if (x > 0 && x < 27)
                                                total += numDecodings(s.substr(2));
                                }
                        }

                        rec[s.size()] = total;
                }

                return total;
        }
};
