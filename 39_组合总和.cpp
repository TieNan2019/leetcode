class Solution {
public:
        int recursion(int items[] , int len, const vector<int> &candidates, int target, int start, vector<vector<int>> &ans) {
                if (target == 0) {
                        ans.emplace_back(items, items + len);
                        return 0;
                }

                if (target < 0)
                        return 0;

                for (int i = start; i < candidates.size(); i++) {

                        items[len] = candidates[i];
                        recursion(items, len + 1, candidates, target - candidates[i], i, ans);
                }

                return 0;
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
                int *items = new int[target];
                memset(items, 0, target);

                vector<vector<int>> ans;

                recursion(items, 0, candidates, target, 0, ans);

                return ans;
        }
};
