class Solution {
public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
        {
                map<int, int> dict;
                for(int i = 0; i < arr2.size(); i++)
                        dict[arr2[i]] = i + 1;

                sort(arr1.begin(), arr1.end(),
                [&](int x, int y){
                        int xIndex = arr1.size() + x;
                        int yIndex = arr1.size() + y;

                        if (dict.find(x) != dict.end())
                                xIndex = dict[x];
                        if (dict.find(y) != dict.end())
                                yIndex = dict[y];

                        return xIndex < yIndex ? true : false;
                });

                return arr1;
        }
};
