class Solution {
public:
        vector<int> minSubsequence(vector<int>& nums) {
                sort(nums.begin(), nums.end());

                int sum = accumulate(nums.begin(), nums.end(), 0);

                int seq = 0;
                vector<int> ans;
                for (auto it = nums.rbegin(); it != nums.rend(); it++) {
                        sum -= *it;
                        seq += *it;
                        ans.push_back(*it);

                        if (seq > sum)
                                return ans;
                }

                return ans;
        }
};
