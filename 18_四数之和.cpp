class Solution {
public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
                if (nums.size() < 4)
                        return {};

                vector<vector<int>> ans;
                sort(nums.begin(), nums.end());

                for (int i = 0; i < nums.size() - 3; i++) {
                        if (target <= 0 && nums[i] > 0)
                                break;

                        if (i > 0 && nums[i] == nums[i-1])
                                continue;

                        for (int j = i + 1; j < nums.size() - 2; j++) {
                                if (j > i+1 && nums[j - 1] == nums[j])
                                        continue;
                                
                                int t = target - nums[i] - nums[j];

                                int head = j + 1, tail = nums.size() - 1;

                                while (head < tail) {
                                        if (nums[head] + nums[tail] == t) {
                                                ans.push_back({nums[i], nums[j], nums[head], nums[tail]});

                                                head++, tail--;
                                                while (head < tail && nums[head] == nums[head-1]) head++;
                                                while (head < tail && nums[tail] == nums[tail+1]) tail--;
                                        }
                                        else if (nums[head] + nums[tail] < t) {
                                                head++;
                                        }
                                        else {
                                                tail--;
                                        }
                                }
                        }
                }


                return ans;
        }
};
