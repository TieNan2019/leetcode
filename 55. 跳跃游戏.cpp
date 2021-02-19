class Solution {
public:
        bool canJump(vector<int>& nums) {
                nums.back() = 1;

                int farest = 0;
                for (int i = 0; i < nums.size() - 1; i++) {
                        farest = max(farest, nums[i] + i);

                        if (i >= farest && nums[i] == 0)
                                return false;
                }

                return farest >= nums.size() - 1;
        }
};
