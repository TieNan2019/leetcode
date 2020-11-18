class Solution {
public:
        int findShortestSubArray(vector<int>& nums)
        {
                map<int, int> counter;
                map<int, vector<int>> pos;

                for (int i = 0; i < nums.size(); i++) {
                        int x = nums[i];
                        ++counter[x];

                        if (pos[x].empty()) {
                                pos[x].push_back(i);
                                pos[x].push_back(i);
                        }
                        else {
                                pos[x][1] = i;
                        }
                }


                int len = 0;
                int maxDegree = 0;
                for (auto it : counter) {
                        if (it.second > maxDegree) {
                                maxDegree = it.second;
                                len = pos[it.first][1] - pos[it.first][0] + 1;
                                // cout << it.first << " -- " << maxDegree << " : " << pos[it.first][0] << ", " << pos[it.first][1] << " --- " << len << endl;
                        }
                        else if (it.second == maxDegree) {
                                int l = pos[it.first][1] - pos[it.first][0] + 1;
                                // cout << it.first << "--" << maxDegree << " : " << pos[it.first][0] << ", " << pos[it.first][1] << endl;

                                len = min(l, len);
                        }
                }

                return len;
        }
};
