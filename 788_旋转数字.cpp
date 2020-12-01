class Solution {
public:
        int isGood(int n) {
                switch (n) {
                        case 2: case 5: case 6: case 9:
                                return 1;
                        case 0: case 1: case 8:
                                return 0;
                        default:
                                return -1;
                }
        }

        int rotatedDigits(int N) {
                int cnt = 0;


                for (int i = 2; i <= N; i++) {
                        int sum = 0;
                        bool jmp = false;

                        int k = i;

                        while (k) {
                                int n = k % 10;
                                k /= 10;
                                int ret = isGood(n);

                                if (ret == -1) {
                                        jmp = true;
                                        break;
                                }

                                sum += ret;
                        }

                        if (jmp)
                                continue;

                        if (sum)
                                cnt++;
                }

                return cnt;
        }
};
