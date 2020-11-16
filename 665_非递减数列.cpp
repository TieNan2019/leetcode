class Solution {
public:
        bool checkPossibility(vector<int>& nums) {
                stack<int> s;
                // 哨兵，保证程序的简洁性，避免复杂边界条件判断
                s.push(INT_MIN);
                // 修改数字的次数
                int cnt = 0;

                for (int i = 0; i < nums.size(); i++) {
                        int x = nums[i];
                        
                        // 条件符合直接入栈
                        if (x >= s.top())
                                s.push(x);
                        else {
                                // 当不符合递增时，存在两种可能性
                                // 1. 栈顶的数据太大，阻拦来后续数据的进入
                                // 2. 扫描到的数据太小，应该剔除

                                // 弹出栈顶元素，保存起来
                                int top = s.top();
                                s.pop();

                                //  如果弹出栈顶以后可以继续进行，说明栈顶元素太大了
                                if (s.top() <= x)
                                        s.push(x);
                                // 如果栈顶弹出后仍然不能将扫描到的数据入栈，则说明数据太小了，
                                // 只有修改当前数据才能1次机会修改正确，还原堆栈
                                else
                                        s.push(top);

                                // 记录这次修改
                                cnt++;

                                // 超过一次直接返回不能
                                if (cnt > 1)
                                        return false;
                        }
                }

                return true;
        }
};
