class Solution {
public:
        void merge(vector<int>& A, int m, vector<int>& B, int n) {
                int tail = A.size() - 1;

                m--, n--;

                while (n >= 0) {
                        if (m >= 0 && A[m] > B[n]) {
                                A[tail] = A[m];
                                m--;
                        }
                        else {
                                A[tail] = B[n];
                                n--;
                        }
                        tail--;
                }
        }
};
