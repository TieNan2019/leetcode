class Solution {
public:
        bool isPowerOfFour(int n) {
                if (n & 0x55555555)
                        if ((n & (n - 1)) == 0)
                                return true;

                return false;
        }
};
