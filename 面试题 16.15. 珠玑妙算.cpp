class Solution {
public:
        vector<int> masterMind(string solution, string guess) {
                map<char, int> counter;

                for (char ch : solution)
                        counter[ch]++;
                
                int hit = 0, got = 0;
                for (int i = 0; i < solution.size(); i++) {
                        if (guess[i] == solution[i])
                                hit++;
                        if (counter[guess[i]] > 0) {
                                got++;
                                counter[guess[i]]--;
                        }
                }

                return {hit, got - hit};
        }
};
