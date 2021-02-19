class Solution {
public:
        int longestOnes(vector<int>& A, int K) {
                int maxLen = 0;

                int head = 0;
                int tail = head + 1;
                int zeros = A.front() == 0;

                while (head < A.size()) {
                        if (zeros > K) {
                                if (A[head] == 0)
                                        zeros--;
                                head++;
                        }
                        else if (tail >= A.size()) {
                                maxLen = max(tail - head, maxLen);

                                if (A[head] == 0)
                                        zeros--;
                                head++;
                        }
                        else {
                                maxLen = max(tail - head, maxLen);
                                if (A[tail] == 0)
                                        zeros++;
                                tail++;
                        }
                }
                
                return maxLen;
        }
};
