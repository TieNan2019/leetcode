// LTE
class Solution {
public:
        map<int, map<bool, int>> rec;
        int recursion(vector<int> & cost, int index = 0, bool canSkip = true) {

                if (index == cost.size()-1 && canSkip)
                        return 0;
                if (index == cost.size()-1 && !canSkip)
                        return cost[index];
                
                if (rec[canSkip].find(index) != rec[canSkip].end())
                        return rec[index][canSkip];

                // 跳一步
                int jump = INT_MAX;

                if (canSkip) {
                        jump = recursion(cost, index + 1, false);
                        // rec[index][false] = jump;
                }

                // 不跳
                int step = cost[index] + recursion(cost, index + 1, true);
                // rec[index][true] = step;

                int total = jump < step ? jump : step;

                rec[index][canSkip] = total;

                return total;
        }

        int minCostClimbingStairs(vector<int>& cost) {
                return recursion(cost);
        }
};
