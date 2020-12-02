class Solution {
public:
        int numSpecialEquivGroups(vector<string>& A) {
                set<string> s;

                for (string word : A) {
                        vector<int> arr(52, 0);

                        for (int i = 0; i < word.size(); i++)
                                arr[word[i] - 'a' + (i % 2) * 26]++;
                        
                        string hashed;
                        for (int x : arr)
                                hashed = hashed + to_string(x);

                        s.insert(hashed);
                }

                return s.size();
        }
};
