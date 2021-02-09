class Solution {
public:
        int maximum(int a, int b) {
                long x = a;
                long y = b;

                unsigned long delta = ((x - y) >> 63) + 1;

                return delta * a + (1 - delta) * b;
        }
};
