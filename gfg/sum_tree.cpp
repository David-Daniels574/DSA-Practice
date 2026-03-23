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

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    bool ans=true;
    int recur(Node* root){
        if(root->left!=NULL && root->right!=NULL){
            int left=recur(root->left);
            int right=recur(root->right);
            if(root->data!=left+right){
                ans=false;
            }
            root->data*=2;
        }
        else if(root->left!=NULL){
            int left=recur(root->left);
            if(root->data!=left){
                ans=false;
            }
            root->data*=2;
        }
        else if(root->right!=NULL){
            int right=recur(root->right);
            if(root->data!=right){
                ans=false;
            }
            root->data*=2;
        }
        return root->data;
    }
  
    bool isSumTree(Node* root) {
        recur(root);
        return ans;
    }
};