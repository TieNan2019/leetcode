class Solution {
public:
        bool isStraight(vector<int>& nums) {
                sort(nums.begin(), nums.end());

                int thisCheck = 0;
                int last;
                int zeros = 0;

                while (thisCheck < nums.size() && nums[thisCheck] == 0) {
                        thisCheck++;
                        zeros++;
                }
                if (thisCheck == nums.size())
                        return true;

                last = nums[thisCheck++];

                for (; thisCheck < nums.size(); thisCheck++) {
                        if (nums[thisCheck] <= last)
                                return false;
        
                        if (nums[thisCheck] == last + 1) {
                                last = nums[thisCheck];
                                continue;
                        }

                        if (zeros >= nums[thisCheck] - last - 1) {
                                zeros -= nums[thisCheck] - last - 1;
                                last = nums[thisCheck];
                        }
                        else {
                                return false;
                        }
                }

                return true;
        }
};
