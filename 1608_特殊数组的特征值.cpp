class Solution {
public:
        int specialArray(vector<int>& nums) {
                sort(nums.begin(), nums.end());

                int i;
                for (i = 0; i < nums.size(); i++) {
                        if (i == 0 && nums.back() < i)
                                return i;
                        else if (nums[nums.size() - 1 - i] < i
                        && nums[nums.size() - i] >= i)
                                return i;
                }


                return nums.front() >= i ? nums.size() : -1;
        }
};
