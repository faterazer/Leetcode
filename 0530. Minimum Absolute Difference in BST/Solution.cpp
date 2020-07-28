#include <algorithm>
#include <numeric>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        int ans = numeric_limits<int>::max();
        inorder(root, pre, ans);
        return ans;
    }

private:
    void inorder(TreeNode *root, TreeNode *&pre, int &ans)
    {
        if (!root)
            return;
        inorder(root->left, pre, ans);
        if (pre)
            ans = min(abs(root->val - pre->val), ans);
        pre = root;
        inorder(root->right, pre, ans);
    }
};