class Solution {
public:
        int longestOnes(vector<int>& A, int K) {
                int head = 0;
                int tail = 0;
                int nextStep = 0;

                /* 扫描到的最大长度 */
                int maxLen = 0;
                /* 当前序列长度 */
                int len = 0;

                int leftFill = K;

                int last = 0;
                while (head < A.size()) {
                        if (tail == A.size() || (A[tail] == 0 && leftFill == 0)) {
                                maxLen = max(len, maxLen);


                                if (head == nextStep) {
                                        len = 0;
                                        head = tail;
                                        nextStep = head;
                                }
                                else {
                                        len = 1;
                                        head = nextStep;
                                        tail = head;
                                }


                                leftFill = K;
                        }
                        else if (A[tail] == 0) {
                                leftFill--;
                                len++;
                        }
                        else if (A[tail] == 1) {
                                len++;
                                if (last == 0 && head == nextStep)
                                        nextStep = tail;
                        }


                        if (tail < A.size())
                                last = A[tail];
                        tail++;
                }
                maxLen = max(len, maxLen);

                int re = A.size() - 1;
                len = 0;
                while (re > 0 && K > 0) {
                        switch(A[re]) {
                                case 0:
                                        K--;
                                default:
                                        break;
                        }
                        len++;
                        re--;
                }


                return max(maxLen, len);
        }
};
