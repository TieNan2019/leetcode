class Solution {
public:
        int longestOnes(vector<int>& A, int K) {
                A.push_back(-1);

                vector<int> zeros(A.size());
                int z = 0;
                for (int i = 0; i < A.size(); i++) {
                        zeros[i] = z;

                        if (A[i] == 0)
                                z++;
                }

                int maxLen = 0;

                int head = 0;
                int tail = head + 1;
                while (head < A.size()) {
                        if (tail >= A.size() || zeros[tail] - zeros[head] > K)
                                head++;
                        else {
                                maxLen = max(tail - head, maxLen);
                                tail++;
                        }
                }
                
                return maxLen;
        }
};
