class Solution {
public:
        map<int, map<bool, int>> rec;

        int recursion(vector<int> & cost, int index = 0, bool canSkip = true) {
                vector<int> paths(cost.size(), INT_MAX);
                paths[paths.size()-1] = cost[cost.size()-1];
                paths[paths.size()-2] = cost[cost.size()-2];

                for (int i = paths.size() - 3; i >= 0; i--) {
                        int jump = cost[i] + paths[i + 2];
                        int walk = cost[i] + paths[i + 1];

                        paths[i] = jump < walk ? jump : walk;
                }

                return paths.front() < paths[1] ? paths.front() : paths[1];
        }

        int minCostClimbingStairs(vector<int>& cost) {
                return recursion(cost);
        }
};
