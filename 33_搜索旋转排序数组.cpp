class Solution {
public:
        int search(vector<int>& nums, int target) {
                int left = 0, right = nums.size() - 1;

                while (left <= right) {
                        int mid = (right - left) / 2 + left;

                        /* 命中则直接返回 */
                        if (nums[mid] == target)
                                return mid;
                        /* 如果 right 对应的值 小于 mid, 则 [left, mid] 均为递增序列 */
                        else if (nums[mid] > nums[left]) {
                                /* 如果 target 落在 [left, mid), 则直接可以确定区间 */
                                if (target >= nums[left] && target < nums[mid])
                                        right = mid - 1;
                                else
                                /* 不在左侧的连续区间内, 虽然不能确定位置, 但是可以肯定目标值出现在 mid 右侧 */
                                        left = mid + 1;
                        }
                        /* 同理 如果 mid < right 对应的值, 则 [mid, right] 均为递增序列 */
                        else if (nums[mid] < nums[right]) {
                                /* 如果 target 落在 (mid, right], 直接缩小范围 */
                                if (target > nums[mid] && target <= nums[right])
                                        left = mid + 1;
                                else
                                /* 同理, 虽然左侧情况位置, 但是可以确定 target 在 mid 左侧 */
                                        right = mid - 1;
                        }
                        /* mid 不可能既小于 left 又大于 right, 
                        因为 left < right 时, left 必然是最小值, 而 left 不是最小值时, left 必然大于 right,
                        因此只有 mid == left 或者 mid == right 时才有可能到达此分支,
                        前面已经对 nums[mid] == target 做过判断, 因此如果 left 不可能对应 target */
                        else
                                left++;
                }


                return -1;
        }
};
