class Solution {
public:
        int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
                int right = 0;
                for (int i = start; i % distance.size() != destination; i++) {
                        right += distance[i % distance.size()];
                }

                int left = 0;
                for (int i = destination; i % distance.size() != start; i++)
                        left += distance[i % distance.size()];

                return min(right, left);
        }
};
