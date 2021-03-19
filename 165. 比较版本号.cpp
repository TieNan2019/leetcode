class Solution {
public:
        int strCmp(const string &a, const string &b) {
                int i = 0, j = 0;

                while (i < a.size() && a[i] == '0')
                        i++;
                while (j < b.size() && b[j] == '0')
                        j++;

                if (i == a.size() && j == b.size())
                        return 0;
                else if (i == a.size())
                        return -1;
                else if (j == b.size())
                        return 1;
                else if (a.size() - i > b.size() - j)
                        return 1;
                else if (a.size() - i < b.size() - j)
                        return -1;
                else if (a.substr(i) > b.substr(j))
                        return 1;
                else if (a.substr(i) < b.substr(j))
                        return -1;

                return 0;
        }


        int compareVersion(string version1, string version2) {
                int ret1;
                int ret2;

                stringstream ss1(version1);
                stringstream ss2(version2);

                string seg1, seg2;

                while (true) {
                        getline(ss1, seg1, '.');
                        getline(ss2, seg2, '.');
                        if (seg1.empty() && seg2.empty())
                                return 0;
                        else if (seg1.empty())
                                seg1 = "0";
                        else if (seg2.empty())
                                seg2 = "0";

                        int ret = strCmp(seg1, seg2);

                        if (ret)
                                return ret;
                        seg1.clear(), seg2.clear();
                }

                return 0;
        }
};
