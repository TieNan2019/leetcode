class Solution {
public:
        inline bool zeroOut(int x) {
                while (x) {
                        int part = x % 10;
                        x /= 10;

                        if (part == 0)
                                return false;
                }

                return true;
        }

        vector<int> getNoZeroIntegers(int n) {
                int a = n / 2;
                int b = n - a;
                while (1) {
                        if (zeroOut(a) && zeroOut(b))
                                return {a, b};
                        a--, b++;
                }

                return {};
        }
};
