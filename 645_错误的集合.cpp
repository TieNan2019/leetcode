class Solution {
public:
        vector<int> findErrorNums(vector<int>& nums) {
                sort(nums.begin(), nums.end());
                
                // 如果序列可列出，并且缺失值只有一个，可以采用一下方法：
                // 第一次想到对遍历技巧，如果目标以某种规律构成一个序列，
                // 可以通过设置一个检查值，每当在序列中遇到该值就将这个变量
                // 修改为后一个，经过一次遍历即可到缺失值
                int left = 1;

                int dup = 0;
                for (int i = 0; i < nums.size() - 1; i++) {
                        // 当 left 期待的值在序列中出现
                        if (nums[i] == left)
                                // left 更新为下一个值，继续监听遍历过程
                                left++;
                        if (nums[i] == nums[i+1])
                                dup = nums[i];
                }
                if (left == nums.back())
                        left++;

                return {dup, left};
        }
};
