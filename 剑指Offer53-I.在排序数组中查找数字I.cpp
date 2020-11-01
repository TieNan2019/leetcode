class Solution {
public:
        int search(vector<int>& nums, int target) {
                // 左边界
                int left = 0, right = nums.size();
                int mid;

                while (left < right) {
                        mid = left + (right - left) / 2;

                        if (nums[mid] == target) {
                                right = mid;
                        }
                        else if (nums[mid] < target) {
                                left = mid + 1;
                        }
                        else if (nums[mid] > target) {
                                right = mid;
                        }
                }

                int leftBound = left;

                // 右边界
                left = 0, right = nums.size();

                while (left < right) {
                        mid = left + (right - left) / 2;

                        if (nums[mid] == target) {
                                left = mid + 1;
                        }
                        else if (nums[mid] < target) {
                                left = mid + 1;
                        }
                        else if (nums[mid] > target) {
                                right = mid;
                        }
                }

                // cout << left << " " << leftBound << endl;
                return left - leftBound;
        }
};
