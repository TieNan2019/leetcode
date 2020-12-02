class Solution {
public:
        vector<int> shortestToChar(string S, char C) {
                vector<int> dist(S.size(), INT_MAX);
                vector<int> idx;

                for (int i = 0; i < S.size(); i++)
                        if (S[i] == C)
                                idx.push_back(i);

                for (int center : idx) {
                        int i = center;
                        dist[i] = 0;
                        do {
                                dist[i] = min(center - i, dist[i]);
                                i--;
                        } while (i >= 0 && S[i] != C);

                        i = center;
                        do {
                                dist[i] = min(i - center, dist[i]);
                                i++;
                        } while (i < S.size() && S[i] != C);
                }

                return dist;
        }
};
