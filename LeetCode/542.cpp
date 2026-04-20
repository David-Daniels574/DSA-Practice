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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // because we are doing in place , the 1 value shouldnt be treated as a
        // distance
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) {
                    mat[i][j] = INT_MAX - 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] > 0) {
                    if (i == 0 && j == 0) {
                        continue;
                    } else if (i == 0) {
                        mat[i][j] = min(mat[i][j], mat[i][j - 1] + 1);
                    } else if (j == 0) {
                        mat[i][j] = min(mat[i][j], mat[i - 1][j] + 1);
                    } else {
                        mat[i][j] = min(mat[i][j],
                                        min(mat[i - 1][j], mat[i][j - 1]) + 1);
                    }
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] > 0) {
                    if (i == m - 1 && j == n - 1) {
                        continue;
                    } else if (i == m - 1) {
                        mat[i][j] = min(mat[i][j], mat[i][j + 1] + 1);
                    } else if (j == n - 1) {
                        mat[i][j] = min(mat[i][j], mat[i + 1][j] + 1);
                    } else {
                        mat[i][j] = min(mat[i][j],
                                        min(mat[i + 1][j], mat[i][j + 1]) + 1);
                    }
                }
            }
        }

        return mat;
    }
};