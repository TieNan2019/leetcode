class Solution {
public:
        bool isWiggle(const vector<int> &nums, const vector<bool> &mask){
                vector<int> seq;
                seq.reserve(nums.size());
                for (int i = 0; i < nums.size(); i++)
                        if (mask[i])
                                seq.push_back(nums[i]);

                if (seq.size() < 2)
                        return true;
                if (seq.size() == 2 && seq[0] == seq[1])
                        return false;

                for (int i = 1; i < seq.size() - 1; i++)
                        if (((seq[i+1] - seq[i]) * (seq[i] - seq[i-1])) >= 0)
                                return false;

                return true;
        }

        int recursion(const vector<int> nums, vector<bool> mask, int depth = 0) {
                // 递归终止, 判断当前数组是否为摆动序列
                if (depth == nums.size())
                        if (isWiggle(nums, mask))
                                return accumulate(mask.begin(), mask.end(), 0);
                        else
                                return 0;

                int x = recursion(nums, mask, depth + 1);
                mask[depth] = false;
                int y = recursion(nums, mask, depth + 1);

                return x > y ? x : y;
        }

        int wiggleMaxLength(vector<int>& nums) {
                vector<bool> mask(nums.size(), true);
                return recursion(nums, mask);
        }
};
