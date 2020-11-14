class Solution {
public:
        vector<string> summaryRanges(vector<int>& nums) {
                if (nums.empty())
                        return {};

                int head = nums.front();
                vector<string> res;

                for (int i = 1; i < nums.size(); i++) {
                        if ((long)nums[i] - nums[i-1] != 1) {
                                if (nums[i-1] == head)
                                        res.emplace_back(to_string(head));
                                else {
                                        res.emplace_back(
                                                to_string(head) + "->"
                                                + to_string(nums[i-1]));
                                }

                                head = nums[i];
                        }
                }

                if (nums.back() == head)
                        res.emplace_back(to_string(head));
                else {
                        res.emplace_back(to_string(head) + "->" + to_string(nums.back()));
                }

                return res;
        }
};
