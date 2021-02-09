class Solution {
public:
        int massage(vector<int>& nums) {
                switch(nums.size()) {
                        case 0:
                                return 0;
                        case 1:
                                return nums.front();
                        case 2:
                                return max(nums[0], nums[1]);
                        default:
                                break;
                }

                vector<int> minutes(nums.begin(), nums.end());
                minutes.rbegin()[2] = nums.rbegin()[2] + nums.back();

                for (int i = nums.size() - 4; i >= 0; i--) {
                        minutes[i] = max(minutes[i + 2], minutes[i + 3]) + nums[i];
                }

                return max(minutes[0], minutes[1]);
        }
};
