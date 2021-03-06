#include <algorithm>
#include <numeric>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int minDiffInBST_MK1(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        int ans = numeric_limits<int>::max();
        inorder(root, pre, ans);
        return ans;
    }

    int minDiffInBST_MK2(TreeNode *root)
    {
        int ans = numeric_limits<int>::max();
        TreeNode *pre = nullptr;
        while (root) {
            if (pre)
                ans = min(ans, abs(root->val - pre->val));
            if (!root->left) {
                pre = root;
                root = root->right;
            }
            else {
                TreeNode *succ = getSuccessor(root);
                if (!succ->right) {
                    succ->right = root;
                    root = root->left;
                }
                else {
                    succ->right = nullptr;
                    pre = root;
                    root = root->right;
                }
            }
        }
        return ans;
    }

    int minDiffInBST_MK3(TreeNode *root)
    {
        int ans = numeric_limits<int>::max();
        TreeNode *pre = nullptr;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pre)
                ans = min(ans, abs(root->val - pre->val));
            pre = root;
            root = root->right;
        }
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

    TreeNode* getSuccessor(TreeNode *root)
    {
        TreeNode *p = root->left;
        while (p->right && p->right != root)
            p = p->right;
        return p;
    }
};
