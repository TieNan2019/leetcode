/* LTE */

class Solution {
public:
        int recursion(const vector<int> &nums, vector<int> seq = {}, int n = 0) {
                if (n == nums.size())
                        return seq.size();

                // 能走到这一步说明前面一定是摆动数列
                if (seq.size() == 1)
                        if (nums[n] == seq.back())
                                return seq.size() - 1;

                if (seq.size() == 2)
                        if (seq[0] == seq[1])
                                return seq.size() - 1;

                if (seq.size() >= 2)
                        if ((nums[n] - seq.back()) * (seq.back() - seq[seq.size()-2]) >= 0)
                                // 此处应该返回长度, 所以不做 -1 处理
                                return seq.size();



                int skip = recursion(nums, seq, n + 1);

                seq.push_back(nums[n]);
                int noSkip = recursion(nums, seq, n + 1);
                
                
                return skip > noSkip ? skip : noSkip;
        }

        int wiggleMaxLength(vector<int>& nums) {
                return recursion(nums);
        }
};
