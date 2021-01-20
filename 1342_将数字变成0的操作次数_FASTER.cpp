class Solution {
public:
        int numberOfSteps (int num) {
                int cnt = 0;

                while (num) {
                        switch(num & 1) {
                                /* 如果是 1 需要 - 1 并右移 */
                                case 1:
                                        cnt += 2;
                                        break;
                                /* 如果是 0 只需要右移 */
                                case 0:
                                        cnt++;
                                        break;
                                default:
                                        break;
                        }
                        num >>= 1;
                }

                /* 最高位不需要右移，因此从总计数中减去 */
                return max(cnt - 1, 0);
        }
};
