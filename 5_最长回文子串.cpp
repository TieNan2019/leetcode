class Solution {
public:
        string longestPalindrome(string s) {
                if (s.empty())
                        return "";

                /* 一个字符可构成最短回文字符串为 */
                string ans(1, s.front());

                int mid = 0;
                /* 最短的情况已经在初始化的时候举出，因此不需要考虑最后一个字符是否是中心的问题 */
                while (mid + 1 < s.size()) {
                        /* 奇数长度字符串, 从中心扩散 */
                        int left = mid, right = mid;
                        while (1) {
                                if (left - 1 < 0 || right + 1 >= s.size())
                                        break;
                                if (s[left-1] != s[right+1])
                                        break;

                                /* 贪心扩大窗口 */
                                left--, right++;
                        }

                        /* 检查是否满足更新结果的要求 */
                        if (right - left + 1 > ans.size())
                                ans = s.substr(left, right - left + 1);

                        /* 偶数长度字符串, 从 mid 和 mid + 1 开始扩散 */
                        if (s[mid] == s[mid + 1]) {
                                left = mid, right = mid + 1;
                                while (1) {
                                        if (left - 1 < 0 || right + 1 >= s.size())
                                                break;
                                        if (s[left-1] != s[right+1])
                                                break;

                                        /* 贪心扩张窗口 */
                                        left--, right++;
                                }

                                /* 检查是否满足更新结果的要求 */
                                if (right - left + 1 > ans.size())
                                        ans = s.substr(left, right - left + 1);
                        }

                        /* 移动中心 */
                        mid++;
                }

                return ans;
        }
};
