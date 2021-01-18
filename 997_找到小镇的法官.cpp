class Solution {
public:
        int findJudge(int N, vector<vector<int>>& trust) {
                if (trust.empty() && N == 1)
                        return N;
        
                map<int, int> trustCount;
                set<int> notJudge;

                int maxCount = 0;
                int maxIndex = -1;
                for (const auto &v : trust) {
                        trustCount[v.back()]++;

                        if (trustCount[v.back()] > maxCount && notJudge.find(v.back()) == notJudge.end()) {
                                maxCount = trustCount[v.back()];
                                maxIndex = v.back();
                        }

                        notJudge.insert(v.front());
                }

                if (notJudge.find(maxIndex) == notJudge.end() && maxCount == N - 1)
                        return maxIndex;
                else
                        return -1;
        }
};
