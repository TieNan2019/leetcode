class Solution {
public:
        bool isPerfectSquare(int num) {
                int left = 0, right = num;
                int mid;

                while (left <= right) {
                        mid = left + (right - left) / 2;
                        long multi = mid * (long)mid;
                        if (multi == num) {
                                return true;
                        }
                        else if (multi > num) {
                                right = mid - 1;
                        }
                        else if (multi < num) {
                                left = mid + 1;
                        }
                }

                return false;
        }
};
