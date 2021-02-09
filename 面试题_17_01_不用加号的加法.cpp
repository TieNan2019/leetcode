class Solution {
public:
        int add(int a, int b) {
                unsigned int res = 0;

                unsigned up = 0;
                unsigned int x = a, y = b;

                unsigned long factor = 1;

                for (unsigned int i = 0; i < 32; i++) {
                        up <<= i;
                        res |= (x & factor) ^ (y & factor) ^ (up & factor);

                        up = ((x & factor) && (y & factor))
                        || ((x & factor) && (up & factor))
                        || ((y & factor) && (up & factor));

                        factor <<= 1;
                }

                return res;
        }
};
