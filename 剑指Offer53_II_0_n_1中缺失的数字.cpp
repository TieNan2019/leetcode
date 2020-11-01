class Solution {
public:
        int missingNumber(vector<int>& nums) {
                int left = 0, right = nums.size();

                int mid;

                while (left < right) {
                        mid = left + (right - left) / 2;

                        if (nums[mid] == mid) {
                                left = mid + 1;
                        }
                        else if (nums[mid] > mid) {
                                right = mid;
                        }
                }

                return left;
        }
};
