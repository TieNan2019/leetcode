class Solution {
public:
        int quickSqrt(float x) {
                float xhalf = 0.5f * x;
                int i = *(int *)&x;

                i = 0x5f3759df - (i >> 1);
                x = *(float *)&i;
                x = x * (1.5f - xhalf * x * x);

                return 1 / x;
        }

        bool checkPerfectNumber(int num) {
                if (num == 1)
                        return false;

                int sum = 1;

                int half = quickSqrt(num);

                for (int i = 2; i <= half; i++)
                        if (num % i == 0)
                                sum += i + num / i;

                return sum == num;
        }
};
