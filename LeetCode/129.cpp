#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    int ans = 0;
    void recur(TreeNode* root, int cur) {
        cur *= 10;
        cur += root->val;
        if (root->left == NULL && root->right == NULL) {
            ans += cur;
            return;
        }

        if (root->left != NULL) {
            recur(root->left, cur);
        }
        if (root->right != NULL) {
            recur(root->right, cur);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        recur(root, 0);
        return ans;
    }
};