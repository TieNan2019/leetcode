class Solution {
public:

        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
                map<int, int> abDict, cdDict;

                for (int a : A)
                        for (int b : B)
                                abDict[a + b]++;
                for (int c : C)
                        for (int d : D)
                                cdDict[c + d]++;

                int cnt = 0;

                for (auto ab : abDict)
                        cnt += cdDict[-ab.first] * ab.second;

                return cnt;
        }
};
