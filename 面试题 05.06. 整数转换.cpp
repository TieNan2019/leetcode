class Solution {
public:
        int convertInteger(int A, int B) {
                unsigned int delta = (unsigned int)A ^ B;

                int cnt = 0;

                while (delta) {
                        delta &= delta - 1;
                        cnt++;
                }

                return cnt;
        }
};
