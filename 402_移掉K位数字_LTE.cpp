class Solution {
public:
        map<string, map<int, string>> locMax;
        int compare (string a, string b) {
                int lenA = a.size();
                int lenB = b.size();

                int std = lenA > lenB ? lenA : lenB;

                if (a.size() != std)
                        a = string(std - a.size(), '0') + a;
                if (b.size() != std)
                        b = string(std - b.size(), '0') + b;

                for (int i = 0; i < std; i++) {
                        if (a[i] > b[i])
                                return 1;
                        else if (a[i] < b[i])
                                return -1;
                }

                return 0;
        }

        string recursion(string nums, int k) {
                if (k == 0) {
                        return nums;
                }

                if (locMax[nums][k] == "") {
                        string s;
                        string minimum(nums.size(), '9');

                        for (int i = 0; i < nums.size(); i++) {
                                if (i < nums.size() - 1)
                                        s = nums.substr(0, i) + nums.substr(i+1);
                                if (i == nums.size() - 1)
                                        s = nums.substr(0, i);
                                
                                s = move(recursion(s, k - 1));

                                if (compare(s, minimum) == -1)
                                                minimum = move(s);
                        }


                        locMax[nums][k] = minimum;
                }
                

                return locMax[nums][k];
        }

        string removeKdigits(string num, int k) {

                string res = move(recursion(num, k));

                int i;
                for (i = 0; i < res.size() && res[i] == '0'; i++);
                res = move(res.substr(i));

                if (res.empty())
                        res = "0";


                return res;
        }
};
