class Solution {
public:
        int binarySearch(const vector<int> &nums) {
                int left = 0, right = nums.size();

                while (left < right) {
                        int mid = left + (right - left) / 2;

                        if (nums[mid] < 0) {
                                right = mid;
                        }
                        else if (nums[mid] >= 0) {
                                left = mid + 1;
                        }
                }

                return left;
        }
        int countNegatives(vector<vector<int>>& grid) {
                int cnt = 0;
                for (auto & v : grid) {
                        cnt += binarySearch(v);
                }
                
                return grid.size() * grid[0].size() - cnt;
        }
};
