class Solution {
public:
        bool isPossible(vector<int>& nums) {
                vector<vector<int>> que;
                
                for (int x : nums) {
                        bool found = false;
                        for (int i = que.size() - 1; i >= 0; i--) {
                                vector<int> &v = que[i];

                                if (v[1] == x - 1) {
                                        v[0]++;
                                        v[1] = x;
                                        found = true;
                                        break;
                                }
                        }


                        if (!found)
                                que.push_back({1, x});
                }


                for (vector<int> v : que)
                        if (v[0] < 3) {
                                return false;
                        }

                return true;
        }
};
