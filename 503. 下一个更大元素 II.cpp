class Solution {
public:
        /* 测试用例里边有个 [1,2,1] ????? */
        vector<int> nextGreaterElements(vector<int>& nums) {
                vector<int> ans(nums.size(), -1);


                int peakIdx = nums.size() - 1;
                for (int i = 0; i < (int)nums.size() - 1; i++)
                        if (nums[i] > nums[i+1]) {
                                peakIdx = i;
                                break;
                        }

                for (int i = peakIdx - 1; i >= 0; i--) {
                        if (nums[i] == nums[i+1])
                                ans[i] = ans[i+1];
                        else
                                ans[i] = nums[i+1];
                }

                if (peakIdx < (int)nums.size() - 1) {
                        if (nums.back() == nums.front())
                                ans.back() = ans.front();
                        else
                                ans.back() = nums.front();
                }

                for (int i = (int)nums.size() - 2; i > peakIdx; i--) {
                        if (nums[i] == nums[i+1])
                                ans[i] = ans[i+1];
                        else
                                ans[i] = nums[i+1];
                }


                return ans;
        }
};
