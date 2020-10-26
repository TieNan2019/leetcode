/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        TreeNode *recursion(const vector<int> &preorder, 
        const vector<int> &inorder)
        {
                if (preorder.empty())
                        return nullptr;

                int rootVal = preorder.front();
                TreeNode *root = new TreeNode(rootVal);

                if (preorder.size() == 1)
                        return root;

                auto it = find(inorder.begin(), inorder.end(), rootVal);
                vector<int> inLeft(inorder.begin(), it), inRight(it+1, inorder.end());

                /*
                map<int, bool> isRight;
                
                for (int i = 0; i < inRight.size(); i++)
                        isRight[inRight[i]] = true;
                
                auto iter = preorder.begin();
                for (iter = preorder.begin(); iter != preorder.end(); iter++) {
                        if (isRight[*iter])
                                break;
                }
                vector<int> preLeft(preorder.begin()+1, iter), preRight(iter, preorder.end());
                */
                // cout << inLeft.size() << endl;

                vector<int> preLeft(preorder.begin()+1, preorder.begin()+inLeft.size()+1);
                vector<int> preRight(preorder.begin()+inLeft.size()+1, preorder.end());
                
                root->left = recursion(preLeft, inLeft);
                root->right = recursion(preRight, inRight);
                
                /*
                for (auto x : inLeft) cout << x << " "; cout << endl;
                for (auto x : inRight) cout << x << " "; cout << endl;
                for (auto x : preLeft) cout << x << " "; cout << endl;
                for (auto x : preRight) cout << x << " "; cout << endl;
                */

                return root;
        }


        TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder)
        {
                TreeNode *root = recursion(preorder, inorder);

                return root;
        }
};
