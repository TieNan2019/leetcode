class Solution {
public:
        int divide(int dividend, int divisor) {
                int sign = 1;
                long x = dividend, y = divisor;

                if (x < 0) {
                        x = -x;
                        sign = -sign;
                }
                if (y < 0) {
                        y = -y;
                        sign = -sign;
                }

                int shift = 31;
                long res = 0;
                while (shift > -1) {
                        res <<= 1;
                        if (x >= (y << shift)) {
                                x -= y << shift;
                                res++;
                        }

                        shift--;
                }

                if (sign < 0)
                        res = -res;
                
                res = max((long)INT_MIN, res);
                res = min((long)INT_MAX, res);

                return res;
        }
};
