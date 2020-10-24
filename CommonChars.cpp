#include <iostream>

using namespace std;


int main(void) {
        string uniq = "abc";

        string str = "aabbbbbaaaa";
        cout <<  count(str.begin(), str.end(), uniq.c_str()[1]) << endl;

        // cout << str << " : " << c << " : " << cnt << endl;

        return 0;
}
