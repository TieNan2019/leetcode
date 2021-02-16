class Solution {
public:
        int recursion(int *items, int pos, map<int, int> &elements, const int len, vector<vector<int>> &ans) {
                if (pos == len) {
                        ans.emplace_back(items, items + len);
                        
                        return 0;
                }

                for (auto it = elements.begin(); it != elements.end(); it++) {
                        if (it->second == 0)
                                continue;
                        
                        if (pos > 0 && it->first == items[pos - 1])
                                continue;

                        for (int j = 0; j < it->second; j++)
                                items[pos + j] = it->first;
                        
                        for (int k = it->second; k > 0; k--) {
                                it->second -= k;

                                recursion(items, pos + k, elements, len, ans);

                                it->second += k;
                        }

                }

                return 0;
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
                map<int, int> cntr;
                for (int x : nums)
                        cntr[x]++;

                vector<vector<int>> ans;

                int *items = new int[nums.size()];
                memset(items, 0, sizeof(int) * nums.size());

                recursion(items, 0, cntr, nums.size(), ans);

                return ans;
        }
};
