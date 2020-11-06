class Solution {
public:
        int videoStitching(vector<vector<int>>& clips, int T) {
                map<int, int> seek;

                for (vector<int> v : clips)
                        seek[v[0]] = v[1] > seek[v[0]] ? v[1] : seek[v[0]];


                int head = 0;
                int hLimit = 0;

                for (int i = 0; i < clips.size() + 1; i++) {
                        if (head >= T)
                                return i;

                        int bestStep = 0;
                        for (int h = head; h >= hLimit; h--)
                                if (seek.find(h) != seek.end())
                                        bestStep = bestStep > seek[h] ? bestStep : seek[h];

                        hLimit = head;
                        head = bestStep;
                }

                return -1;
        }
};
