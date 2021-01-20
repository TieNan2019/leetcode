class Solution {
public:
        string freqAlphabets(string s) {
                map<string, char> dict {
                        {"1", 'a'},
                        {"2", 'b'},
                        {"3", 'c'},
                        {"4", 'd'},
                        {"5", 'e'},
                        {"6", 'f'},
                        {"7", 'g'},
                        {"8", 'h'},
                        {"9", 'i'},
                        {"10#", 'j'},
                        {"11#", 'k'},
                        {"12#", 'l'},
                        {"13#", 'm'},
                        {"14#", 'n'},
                        {"15#", 'o'},
                        {"16#", 'p'},
                        {"17#", 'q'},
                        {"18#", 'r'},
                        {"19#", 's'},
                        {"20#", 't'},
                        {"21#", 'u'},
                        {"22#", 'v'},
                        {"23#", 'w'},
                        {"24#", 'x'},
                        {"25#", 'y'},
                        {"26#", 'z'}
                };

                string decoded;

                int i = 0;
                while (i < s.size()) {
                        if (i + 3 <= s.size() && dict.find(s.substr(i, 3)) != dict.end()) {
                                // cout << s.substr(i, 3) << endl;

                                decoded = decoded + dict[s.substr(i, 3)];
                                i += 3;
                        }
                        else if (dict.find(s.substr(i, 1)) != dict.end()) {
                                // cout << s.substr(i, 1) << endl;

                                decoded = decoded + dict[s.substr(i, 1)];
                                i++;
                        }
                }

                return decoded;
        }
};
