// LTE

class Solution {
        map<int, int> rec;
public:
        int recursion(const vector<int> & coins, int amount)
        {
                if (amount < 0)
                        return -1;

                if (amount == 0)
                        return 0;

                if (rec.find(amount) != rec.end())
                        return rec[amount];
                
                int total = INT_MAX;
                for (int i = 0; i < coins.size(); i++) {
                        int coin = coins[i];

                        int thisTry = recursion(coins, amount - coin);

                        if (thisTry != -1 && thisTry < total)
                                total = thisTry;
                }

                if (total == INT_MAX)
                        return -1;
                else {
                        rec[amount] = total + 1;
                        return total + 1;
                }
        }

        int coinChange(vector<int>& coins, int amount) {
                return recursion(coins, amount);
        }
};
