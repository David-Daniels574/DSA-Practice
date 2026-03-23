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
    vector<int> v1;
    vector<int> v2;
    void inorder(TreeNode* root, int no) {
        if (no) {
            if (root != NULL) {
                inorder(root->left, no);
                v1.push_back(root->val);
                inorder(root->right, no);
            }
        } else {
            if (root != NULL) {
                inorder(root->left, no);
                v2.push_back(root->val);
                inorder(root->right, no);
            }
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1, true);
        inorder(root2, false);

        int i1 = 0, i2 = 0;
        vector<int> ans;
        int temp;
        while (i1 < v1.size() && i2 < v2.size()) {
            if (v1[i1] > v2[i2]) {
                ans.push_back(v2[i2]);
                i2++;
            } else {
                ans.push_back(v1[i1]);
                i1++;
            }
        }

        while (i1 < v1.size()) {
            ans.push_back(v1[i1]);
            i1++;
        }
        while (i2 < v2.size()) {
            ans.push_back(v2[i2]);
            i2++;
        }
        return ans;
    }
};