class Solution {
public:
        bool canJump(vector<int>& nums) {
                vector<bool> ifpass(nums.size(), false);
                ifpass.back() = true;

                for (int i = nums.size() - 2; i >=0; i--) {
                        for (int j = 1; i + j < nums.size() && j <= nums[i]; j++)
                                if (ifpass[i+j] == true) {
                                        ifpass[i] = true;
                                        break;
                                }
                }


                return ifpass.front();
        }
};
