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

class Solution {
public:
    void recur(string temp, int open, int close, int n, vector<string>& ans) {
    if (temp.size() == 2*n) {
        ans.push_back(temp);
        return;
    }
    if (open < n)
        recur(temp + '(', open + 1, close, n, ans);
    if (close < open)
        recur(temp + ')', open, close + 1, n, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur("",0,0,n,ans);
        return ans;
    }
};