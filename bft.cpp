#include <iostream>
#include <vector>


struct TreeNode {
        int val;
        struct TreeNode * left;
        struct TreeNode * right;

        TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
        TreeNode(void): val(0), left(nullptr), right(nullptr) {}
};


int insertNode()
{
        return 0;
}

int main(void)
{
        std::vector<int> x = {3, 1, 4, 5, 9, 2, 6};

        TreeNode *root;

        return 0;
}
