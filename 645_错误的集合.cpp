class Solution {
public:
        vector<int> findErrorNums(vector<int>& nums) {
                sort(nums.begin(), nums.end());
                int left = 1;

                int dup = 0;
                for (int i = 0; i < nums.size() - 1; i++) {
                        if (nums[i] == left)
                                left++;
                        if (nums[i] == nums[i+1])
                                dup = nums[i];
                }
                if (left == nums.back())
                        left++;

                return {dup, left};
        }
};
