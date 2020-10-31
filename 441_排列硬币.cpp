/* 本题可以看作是搜索数组的左边界 */
class Solution {
public:
        int arrangeCoins(int n) {
                int left = 0, right = n;
                long mid;
                long sum;
                
                while (left <= right) {
                        mid = left + (right - left) / 2;
                        sum = mid * (mid + 1) / 2;

                        // cout << mid << endl;

                        if (sum <= n) {
                                left = mid + 1;
                        }
                        else if (sum > n) {
                                right = mid - 1;
                        }
                        else if (sum == n) {
                                right = mid - 1;
                        }

                }

                return right;
        }
};
