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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return (1 + max(depth(root->left), depth(root->right)));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        int left = depth(root->left);
        int right = depth(root->right);

        if (left == right) {
            return root;
        }
        if (left > right) {
            return subtreeWithAllDeepest(root->left);
        } else {
            return subtreeWithAllDeepest(root->right);
        }
        return root;
    }
};