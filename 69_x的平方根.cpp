class Solution {
public:
        int mySqrt(int x) {
                int left = 0, right = x;
                int mid;

                while (left <= right) {
                        mid = left + (right - left) / 2;
                        
                        long multi = mid * (long)mid;

                        if (multi == x) {
                                return mid;
                        }
                        else if (multi > x) {
                                right = mid - 1;
                        }
                        else if (multi < x) {
                                left = mid + 1;
                        }
                }

                return right;
        }
};
