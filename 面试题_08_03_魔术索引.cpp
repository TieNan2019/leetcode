class Solution {
public:
        int recursion(const vector<int> &nums, int left, int right) {
                // cout << left << " : " << right << endl;
                if (left >= nums.size())
                        return -1;

                if (left == right)
                        return nums[left] == left ? left : -1;

                int mid = left + (right - left) / 2;
                // if (nums[mid] == mid)
                        // return mid;

                int leftArea = recursion(nums, left, mid);
                int rightArea = recursion(nums, mid + 1, right);

                if (leftArea == -1) {
                        // cout << "1 : " << rightArea << endl;
                        return rightArea;
                }
                else if (rightArea == -1) {
                        // cout << "2 : " << leftArea << endl;
                        return leftArea;
                }
                else {
                        // cout << "3 : " << leftArea << " : " << rightArea << endl;
                        return leftArea < rightArea ? leftArea : rightArea;
                }
        }

        int findMagicIndex(vector<int>& nums) {
                int left = 0, right = nums.size();

                return recursion(nums, left, right);
        }
};
