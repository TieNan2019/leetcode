class Solution {
public:
        int numWaterBottles(int numBottles, int numExchange) {
                int empty = 0;
                int full = numBottles;

                int drunk = 0;
                int left = 0;

                while (full) {
                        /* 干杯! */
                        empty = full;
                        drunk += full;

                        /* 上次剩下的瓶子 */
                        empty += left;
                        left = 0;

                        /* 换 */
                        full = empty / numExchange;
                        left = empty % numExchange;
                }

                return drunk;
        }
};
