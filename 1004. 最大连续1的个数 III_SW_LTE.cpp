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
                for (int head = 0; head < A.size() - 1; head++)
                        for (int tail = head + 1; tail < A.size(); tail++) {
                                if (zeros[tail] - zeros[head] <= K)
                                        maxLen = max(tail - head, maxLen);
                        }
                
                return maxLen;
        }
};
