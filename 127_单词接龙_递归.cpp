/* LTE */
class Solution {
public:
        int cmp(const string &a, const string &b) {
                int diff = 0;

                for (int i = 0; i < a.size(); i++)
                        if (a[i] != b[i])
                                diff++;

                return diff;
        }

        int recursion(const string &beginWord, const string &endWord,
        const vector<string> &wordList, vector<bool> available) {

                if (beginWord == endWord)
                        return 0;

                // if (accumulate(available.begin(), available.begin(), 0) == 0)
                        // return -1;

                int total = INT_MAX;
                for (int i = 0; i < available.size(); i++) {
                        if (available[i] && cmp(beginWord, wordList[i]) == 1) {
                                available[i] = false;

                                int oneTry = recursion(wordList[i], endWord, wordList, available);
                                if (oneTry != -1) {
                                        cout << beginWord << " -> " << endWord << endl;

                                        total = total < oneTry ? total : oneTry;
                                }
        
                                available[i] = true;
                        }
                }
                if (total == INT_MAX)
                        return -1;

                return total + 1;
        }

        int ladderLength(string beginWord,
        string endWord, vector<string>& wordList) {
                vector<bool> available(wordList.size(), true);

                int res = recursion(beginWord, endWord, wordList, available) + 1;

                return res != -1 ? res : 0;
        }
};
