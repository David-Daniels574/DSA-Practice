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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> arr(m + n);
        int temp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> tp;
        int side = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (side == 0) {
                for (int j = 0; j < arr[i].size(); j++) {
                    ans.push_back(arr[i][j]);
                }
                side = 1;
            } else {
                for (int j = arr[i].size() - 1; j >= 0; j--) {
                    ans.push_back(arr[i][j]);
                }
                side = 0;
            }
        }

        return ans;
    }
};