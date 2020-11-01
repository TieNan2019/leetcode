class Solution {
        map<int, int> rec;
public:
        int iterator(const vector<int> & coins, int amount)
        {
                vector<int> rec(amount + 1, amount + 1);

                rec[0] = 0;

                for (int i = 1; i <= amount; i++) {
                        for (int coin : coins) {
                                if (i - coin < 0) 
                                        continue;

                                int oneTry = rec[i-coin] + 1;
                                rec[i] = oneTry < rec[i] ? oneTry : rec[i];
                        }
                }

                return rec[amount] != amount + 1 ? rec[amount] : -1;

        }

        int coinChange(vector<int>& coins, int amount) {
                return iterator(coins, amount);
        }
};
