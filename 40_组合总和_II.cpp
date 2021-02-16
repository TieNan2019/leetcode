class Solution {
public:
        void recursion(int *items, int len, const map<int, int>::iterator it, 
        const map<int, int>::iterator end, int target, vector<vector<int>>& ans) {
                /* 满足条件, 添加结果 */
                if (target == 0) {
                        ans.emplace_back(items, items + len);
                        return ;
                }

                /* target 小于 0 不需要继续递归 */
                if (target < 0)
                        return ;
                
                /* 可用元素已经用尽 */
                if (it == end)
                        return ;

                auto next = it;
                next++;

 
                /* 分别按照从多到少的顺序填入元素, 保证当前结果按照字典序储存 */
                for (int i = 0; i <= it->second; i++)
                        items[len + i] = it->first;
                for (int n = it->second; n >= 0; n--)
                        recursion(items, len + n, next, end, target - it->first * n, ans);
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
                /* 对元素进行计数, 避免重复 */
                map<int, int> counter;
                for (const auto &x : candidates)
                        counter[x]++;                

                vector<vector<int>> ans;

                /* 回溯锁保存对路径 */
                int *items = new int[candidates.size() + 1];
                memset(items, 0, candidates.size() + 1);

                /* 递归 */
                recursion(items, 0, counter.begin(), counter.end(), target, ans);

                delete[] items;
                return ans;
        }
};
