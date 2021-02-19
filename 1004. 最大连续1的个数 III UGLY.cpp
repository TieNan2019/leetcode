class Solution {
public:
        int longestOnes(vector<int>& A, int K) {
                int head = 0;
                int tail = 0;

                vector<pair<int, int>> cache;

                int len = 0;
                while (tail < A.size()) {
                        if (A[head] == A[tail]) {
                                len++;
                                tail++;
                        }
                        else {
                                cache.push_back({A[head], len});
                                head = tail;
                                len = 0;
                        }
                }
                cache.push_back({A[head], len});

                int maxLen = 0;
                for (int i = 0; i < cache.size(); i++) {
                        if(cache[i].first == 1) {
                                int fill = K;
                                int j = i;
                                int len = 0;

                                while (j < cache.size()) {
                                        if (cache[j].first == 1)
                                                len += cache[j].second;
                                        else if (fill <= 0)
                                                break;
                                        else if (cache[j].first != 1 && fill > 0){
                                                len += min(fill, cache[j].second);
                                                fill -= cache[j].second;

                                                if (fill < 0)
                                                        break;
                                        }

                                        j++;
                                }

                                maxLen = max(maxLen, len);
                        }
                }

                int i = A.size() - 1;
                int tailLen = 0;
                while (i >= 0 && (A[i] == 1 || K > 0)) {
                        if (A[i] == 0)
                                K--;
                        tailLen++;
                        i--;
                }

                return max(maxLen, tailLen);
        }
};
