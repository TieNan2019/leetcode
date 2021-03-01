class Solution {
public:
        void recursion(int *arr, int start, int len, const vector<int> &nums, const int limit, vector<vector<int>> &ans) {
                ans.emplace_back(arr, arr + len);

                if (len == limit)
                        return ;

                for (int i = start; i < nums.size(); i++) {
                        arr[len] = nums[i];

                        recursion(arr, i + 1, len + 1, nums, limit, ans);
                }

        }

        vector<vector<int>> subsets(vector<int>& nums) {
                int *arr = new int[nums.size()];

                vector<vector<int>> ans;

                recursion(arr, 0, 0, nums, nums.size(), ans);

                delete[] arr;

                return ans;
        }
};
