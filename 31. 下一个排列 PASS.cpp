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


                int index = head;
                int minLarger = INT_MAX;

                for (int i = head + 1; i < nums.size(); i++)
                        if (minLarger > nums[i] && nums[i] > nums[head]) {
                                index = i;
                                minLarger = nums[i];
                        }
                {
                        int tmp = nums[head];
                        nums[head] = nums[index];
                        nums[index] = tmp;
                }

                sort(nums.begin() + head + 1, nums.end());
        }
};
