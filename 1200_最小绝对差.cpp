class Solution {
public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
                sort(arr.begin(), arr.end());

                int minDelta = INT_MAX;
                vector<vector<int>> ans;

                for (int i = 0; i < arr.size() - 1; i++) {
                        int delta = arr[i + 1] - arr[i];

                        if (delta < minDelta) {
                                minDelta = delta;
                                ans.clear();

                                ans.push_back({arr[i], arr[i + 1]});
                        }
                        else if (delta == minDelta)
                                ans.push_back({arr[i], arr[i + 1]});
                }

                return ans;
        }
};
