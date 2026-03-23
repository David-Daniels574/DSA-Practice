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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == NULL) {
            return 0;
        }
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int no_of_nodes = q.size();

            for (int i = 0; i < no_of_nodes; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left == NULL && curr->right == NULL) {
                    return level;
                }
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            level++;
        }

        return 0;
    }
};