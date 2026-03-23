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
    vector<int>v;
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    int idx=0;
    void replace(TreeNode* root){
        if(root!=NULL){
            replace(root->left);
            root->val=v[idx];
            idx++;
            replace(root->right);
        }
    }

    TreeNode* convertBST(TreeNode* root) {
         inorder(root);

        for(int i=v.size()-1 ; i>=1;i--){
            v[i-1]+=v[i];
        }

        replace(root);
    return root;   
    }
};