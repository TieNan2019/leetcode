#include <iostream>
#include <vector>



using namespace std;


struct ListNode {
        int val;
        ListNode *left;
        ListNode *right;

        ListNode(int val): val(val), left(nullptr), right(nullptr) {}
        ListNode() : ListNode(0) {}
};



ListNode * insertNode(ListNode * root, int val)
{
        if (root == nullptr) {
                return new ListNode(val);
        }

        // 如果大于根节点则选择右支
        if (val > root->val)
                root->right = insertNode(root->right, val);

        // 如果小于根节点则选择左支
        else if (val < root->val)
                root->left = insertNode(root->left, val);

        // 如果等于则放弃操作
        else
                return root;

        return root;
}


int recursion(vector<int> nums, ListNode *root)
{
        if (nums.size() == 0)
                return -1;

        int mid = nums.size() / 2;

        cout << nums[mid] << endl;
        root = insertNode(root, nums[mid]);

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());

        recursion(left, root);
        recursion(right, root);

        return 0;
}


int main(void)
{
        ListNode *root;
        vector<int> nums = {0, 1, 2, 3, 4, 5, 6};

        recursion(nums, root);

        return 0;
}
