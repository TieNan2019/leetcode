class Solution {
public:
        bool flag = true;
        int minSteps(int n) {
                if (n == 1)
                        return 0;

                int factor = n - 1;
                while (n % factor)
                        factor--;

                return minSteps(factor) + n / factor;
        }
};
