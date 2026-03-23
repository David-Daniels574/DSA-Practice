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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = INT_MAX, sum = 0;
        if (root == NULL) {
            return 1;
        }
        sum=root->val;
        q.push(root);

        int number_of_nodes_per_level = 0, lev = 1;
        while (!q.empty()) {
            number_of_nodes_per_level = q.size();
            vector<int> level;

            for (int i = 0; i < number_of_nodes_per_level; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            int tsum = 0;
            for (int i = 0; i < level.size(); i++) {
                tsum += level[i];
            }
            if (tsum > sum) {
                sum = tsum;
                ans = lev;
            }
            else if(tsum==sum){
               ans = min(ans, lev); 
            }
            lev++;
        }
        return ans;
    }
};