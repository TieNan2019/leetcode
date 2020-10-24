#include <string>
#include <iostream>



typedef struct {
        char c;
        int n;
} Letter;


class Solution {
public:
        bool isLongPressedName(std::string name, std::string typed) {
                vector<Letter> NameCount;
                vector<Letter> TypedCount;

                if (name == typed)
                        return true;

                while (true) {

                }

                return false;
        }
};



int main(void)
{
        std::string name = "leelee", typed = "lleeelee";

        Solution s;
        std::cout << s.isLongPressedName(name, typed) << std::endl;

        return 0;
}
