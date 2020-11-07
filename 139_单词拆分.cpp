class Solution {
public:
        map<string, bool> dict;
        vector<int> rec;
        set<int> lenDict;

        bool recursion(string s) {
                if (dict[s])
                        return true;

                bool ret = false;
                for (int x : lenDict) {
                        if (dict[s.substr(0, x)]) {
                                if (rec[s.size()-x] == -1) {
                                        rec[s.size()-x] = recursion(s.substr(x)); 
                                }
                                ret = ret || rec[s.size()-x]; 
                        }
                }

                return ret;
        }

        bool wordBreak(string s, vector<string>& wordDict) {
                for (string word : wordDict) {
                        dict[word] = true;
                        lenDict.insert(word.size());
                }

                rec = vector<int>(s.size()+1, -1);
                
                return recursion(s);
        }
};
