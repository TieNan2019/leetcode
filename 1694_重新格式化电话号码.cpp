class Solution {
public:
        string reformatNumber(string number) {
                string filtered(number.size() * 2, '@');

                int len = 0;
                int cnt = 0;
                for (char ch : number) {

                        if (isdigit(ch)) {
                                filtered[len++] = ch;
                                if (cnt == 2)
                                        filtered[len++] = '-';
                                cnt++;
                                cnt %= 3;
                        }
                }

                if (len >= 3)
                        /* 以一个 - 结尾 */
                        if (filtered[len-1] == '-')
                                len--;
                        /* 一个字符 */
                        else if (filtered[len-2] == '-') {
                                filtered[len-2] = filtered[len-3];
                                filtered[len-3] = '-';
                        }
                        
                return filtered.substr(0, len);
        }
};
