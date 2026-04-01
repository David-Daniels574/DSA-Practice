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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++){ 
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};