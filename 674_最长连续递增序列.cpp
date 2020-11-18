class Solution {
public:
        bool backward(string &s, int h, int t) {

                while (h < t) {
                        if (s[h] != s[t]) {
                                return false;
                        }

                        h++, t--;
                }

                return true;
        }
        bool validPalindrome(string s) {
                int h = 0, t = s.size() - 1;

                while (h < t) {
                        if (s[h] != s[t]) {
                                bool ret = false;

                                /* 跨一个字符重新检验并作为新结果 */
                                ret |= backward(s, h+1, t);
                                ret |= backward(s, h, t-1);

                                return ret;
                        }

                        h++, t--;
                }

                return true;
        }
};
