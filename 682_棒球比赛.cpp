class Solution {
public:

        int calPoints(vector<string>& ops) {
                vector<int> score;

                int sum, n;
                for (int i = 0; i < ops.size(); i++) {
                        const string s = ops[i];

                        switch(s[0]) {
                                case '+':
                                        sum = score[score.size()-2] + score.back();
                                        score.push_back(sum);
                                        break;
                                case 'C':
                                        score.pop_back();
                                        break;
                                case 'D':
                                        score.push_back(2 * score.back());
                                        break;

                                default:
                                        n = atoi(s.c_str());
                                        score.push_back(n);
                                        break;
                        }

                        /*
                        for (auto x : score)
                                cout << x << " ";
                        cout << endl;
                        */
                }

                int res = accumulate(score.begin(), score.end(), 0);

                return res;
        }
};
