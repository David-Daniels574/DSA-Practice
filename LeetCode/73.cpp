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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> p;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) {
                    p.push_back({r, c});
                }
            }
        }

        int x, y;
        for (int i = 0; i < p.size(); i++) {
            x = p[i].first;
            y = p[i].second;

            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[x][i] = 0;
            }
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][y] = 0;
            }
        }
    }
};