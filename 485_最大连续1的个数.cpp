class Solution {
public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
                int len = 0;
                int l = 0;
                bool count = false;

                for (int i = 0; i < nums.size(); i++) {
                        switch(nums[i]) {
                                case 1:
                                        l++;
                                        break;

                                default:
                                        len = len > l ? len : l;
                                        l = 0;
                                        break;
                        }
                }

                len = len > l ? len : l;

                return len;
        }
};
