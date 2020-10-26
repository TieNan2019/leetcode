class Solution {
public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
                /* 索引倒排 */
                map<int, vector<int>> invIndex;

                for (int i = 0; i < nums.size(); i++)
                        /* 倒排数组具有从小到大的特性 */
                        invIndex[nums[i]].push_back(i);


                for (auto it = invIndex.begin();
                it != invIndex.end(); it++) {
                        cout << it->first << " : ";
                        for (auto x : it->second)
                                cout << x << ", ";
                        cout << endl;

                        if (it->second.size() > 1)
                                for (int i = 0; i < it->second.size()-1; i++) {
                                        if (it->second[i+1] - it->second[i] <= k)
                                                return true;
                                }
                }

                return false;
        }
};
