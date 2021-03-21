class Solution {
public:
        int hIndex(vector<int>& citations)
        {
                int papers = citations.size();
                int h = 0;

                int left = 0, right = papers - 1;
                while (left <= right) {
                        int mid = (right - left) / 2 + left;

                        if (papers - mid <= citations[mid]) {
                                h = max(h, papers - mid);
                                right = mid - 1;
                        }
                        else if (papers - mid > citations[mid])
                                left = mid + 1;
                }

                return h;
        }
};
