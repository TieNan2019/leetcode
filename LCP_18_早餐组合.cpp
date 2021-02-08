class Solution {
public:
        int binarySearch(const vector<int> arr, const int target) {
                int left = 0, right = arr.size() - 1;

                while (left <= right) {
                        int mid = (right - left) / 2 + left;

                        if (arr[mid] <= target) {
                                left = mid + 1;
                        }
                        else if (arr[mid] > target) {
                                right = mid - 1;
                        }
                }

                return left;
        }

        int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
                sort(staple.begin(), staple.end());
                sort(drinks.begin(), drinks.end());

                map<int, int> cache;

                int methods = 0;
                for (int i = 0; i < staple.size(); i++) {
                        int target = x - staple[i];

                        if (cache.find(target) == cache.end())
                                cache[target] = binarySearch(drinks, target);
                        
                        methods += cache[target];
                }

                return methods;
        }
};
