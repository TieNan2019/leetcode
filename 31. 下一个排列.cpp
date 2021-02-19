class Solution {
public:
        void nextPermutation(vector<int>& nums) {
                int head = nums.size() - 2;
                while (head >= 0 && nums[head] >= nums[head + 1])
                        head--;

                if (head < 0) {
                        reverse(nums.begin(), nums.end());
                        return ;
                }

                int index;
                for (index = nums.size() - 1; index > head && nums[index] <= nums[head]; index--);
                swap(nums[head], nums[index]);

                reverse(nums.begin() + head + 1, nums.end());
        }
};
