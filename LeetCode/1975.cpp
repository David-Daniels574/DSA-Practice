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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0, abs_min = INT_MAX;
        bool is_z = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                abs_min = min(abs_min, abs(matrix[i][j]));
                if (matrix[i][j] < 0) {
                    cnt++;
                } else if (!is_z && matrix[i][j] == 0) {
                    is_z = true;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                ans += abs(matrix[i][j]);
            }
        }
        if (cnt % 2 != 0 && !is_z) {
            ans -= abs_min * 2;
        }
        return ans;
    }
};