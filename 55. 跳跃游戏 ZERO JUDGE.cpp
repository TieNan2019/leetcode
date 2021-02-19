class Solution {
public:
        bool canJump(vector<int>& nums) {
                /* 游戏规则可知, 如果无法避免进入 0 是唯一失败的可能 */
                for (int i = nums.size() - 2; i >= 0; i--) {
                        /* 所以主要任务就是向前逆向找 0 */
                        if (nums[i] > 0)
                                continue;
                        
                        bool jmp = false;
                        int len = 0;
                        int j = i;
                        /* 找到 0 以后就需要找到位于该点之前且可以越过 0 的点 */
                        while (j >= 0) {
                                if (nums[j] > len) {
                                        jmp = true;
                                        break;
                                }

                                j--;
                                len++;
                        }

                        /* 越不过去则直接结束程序 */
                        if (!jmp)
                                return false;
                }

                return true;
        }
};
