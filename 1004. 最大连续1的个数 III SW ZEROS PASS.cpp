class Solution {
public:
        int longestOnes(vector<int>& A, int K) {
                int maxLen = 0;

                int head = 0;
                int tail = head + 1;
                int zeros = A.front() == 0;

                /* head 到 tail 与 zeros 的关系表示为 zeros 表示 [head, tail) 中 0 的计数 */
                while (head < A.size()) {
                        /* 0 多了以后让 head 前进 */
                        if (zeros > K) {
                                /* 如果 head 指向 0, 应该优先把 0 减少一个在让 head 前进 */
                                if (A[head] == 0)
                                        zeros--;
                                head++;
                        }
                        /* 0 的个数不超过阈值 */
                        else if (tail >= A.size()) {
                                /* tail 已达到末尾, 最后检查长度是否为最大值 */
                                maxLen = max(tail - head, maxLen);
                                break;
                        }
                        else {
                                /* tail 在数组中间 */
                                /* 检查长度是否足够大 */
                                maxLen = max(tail - head, maxLen);

                                /* 因为 tail 是开区间, 所以先对 zeros 进行更新, 再移动 tail 指针 */
                                if (A[tail] == 0)
                                        zeros++;
                                tail++;
                        }
                }
                
                return maxLen;
        }
};
