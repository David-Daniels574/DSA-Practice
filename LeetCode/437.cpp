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
    int cnt=0;
    void pre(TreeNode* root, long long sum , int target, unordered_map<long long,int>&mp){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        if(mp[sum-target]>0){
            cnt+=mp[sum-target];
        }
        mp[sum]++;

        pre(root->left,sum,target,mp);
        pre(root->right,sum,target,mp);
        
        mp[sum]--;
        sum-=root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long ,int>mp;
        mp[0]=1;
        pre(root,0,targetSum,mp);
        return cnt;
    }
};