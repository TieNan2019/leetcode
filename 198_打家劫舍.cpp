class Solution {
public:
        int rob(vector<int>& nums) {
                if (nums.size() == 0)
                        return 0;
                if (nums.size() == 1)
                        return nums[0];
        
                vector<int> steal(nums.size(), 0);
                steal[steal.size() - 1] = nums[steal.size() - 1];
                steal[steal.size() - 2] = nums[steal.size() - 2];

                for (int i = steal.size() - 3; i >= 0; i--) {
                        for (int j = i + 2; j < steal.size(); j++) {
                                int oneTry = nums[i] + steal[j];

                                steal[i] = steal[i] > oneTry ? steal[i] : oneTry;
                        }
                }

                return steal[0] > steal[1] ? steal[0] : steal[1];
        }
};
