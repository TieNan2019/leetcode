class Solution {
public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
        {
                if (customers.size() <= X)
                        return accumulate(customers.begin(), customers.end(), 0);
                

                int head = 0, tail = head + X - 1;
                int increasement = 0;
                for (int i = head; i <= tail; i++) {
                        if (grumpy[i])
                                increasement += customers[i];
                }


                int maxInc = increasement;
                while (tail < customers.size() - 1) {
                        if (grumpy[head])
                                increasement -= customers[head];
                        head++;

                        tail++;
                        if (grumpy[tail])
                                increasement += customers[tail];

                        maxInc = max(increasement, maxInc); 
                }


                int base = 0;
                for (int i = 0; i < customers.size(); i++)
                        if (!grumpy[i])
                                base += customers[i];

                return maxInc + base;
        }
};
