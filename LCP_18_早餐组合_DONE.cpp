class Solution {
public:

        int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
                sort(staple.begin(), staple.end());
                sort(drinks.begin(), drinks.end());

                int head = 0, tail = drinks.size() - 1;

                long methods = 0;
                while (head < staple.size()) {

                        while (tail >= 0 && staple[head] + drinks[tail] > x) {
                                tail--;
                        }

                        methods += tail + 1;
                        head++;
                }

                return methods % 1000000007;
        }
};
