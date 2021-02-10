class Solution {
public:
        int lengthOfLongestSubstring(string s) {
                if (s.empty())
                        return 0;

                bool path[128] {false};

                int uniqLen = 1;
                path[s.front()] = true;

                int head = 0;
                int tail = 0;

                /* 这里用头指针来判断范围，因为后续头指针可能会和尾指针重合, 此时尾指针就必然可以前进 */
                while (head < s.size()) {
                        /* 尾指针试图前进 : 当前进会超出字符串范围 或者 下一个目标字符会导致元素重复出现 时 前进失败 */
                        if (tail + 1 < s.size() && !path[s[tail+1]]) {
                                /* 滑动窗口扩张, 尾指针后移, 并将下一个进入窗口的字符加入缓存 */
                                path[s[tail+1]] = true;
                                tail++;

                                /* 只有尾指针前进时才能导致窗口扩张，在窗口扩张时更新长度的最大值 */
                                uniqLen = max(uniqLen, tail - head + 1);
                        }
                        /* 尾指针到达字符串末尾, 或者 尾指针的下一个目标字符会导致重复 */
                        else {
                                /* 原来头指针指向的字符将要排除到窗口之外，因此去除其缓存 */
                                path[s[head]] = false;
                                /* 头指针前进，缩小窗口，这样可以让尾指针继续前进 */
                                head++;
                        }
                }

                return  uniqLen;
        }
};
