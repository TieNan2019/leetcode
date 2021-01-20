class Solution {
public:
        bool checkIfExist(vector<int>& arr) {
                map<int, int> invIndex;

                for (int i = 0; i < arr.size(); i++)
                        invIndex[arr[i]] = i;
                
                for (int i = 0; i < arr.size(); i++) {
                        if (invIndex.find(arr[i] * 2) != invIndex.end()) {
                                if (i != invIndex[arr[i] * 2])
                                        return true;
                        }
                }

                return false;
        }
};
