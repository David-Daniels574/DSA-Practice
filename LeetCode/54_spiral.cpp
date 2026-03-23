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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int r = 0, c = 1, i = 0, j = 0;
        vector<int> ans;
        while (ans.size() < m * n) {
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;
            int new_i = i + r, new_j = j + c;
            
            if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
                if (r == 0 && c == 1) { r = 1; c = 0; }
                else if (r == 1 && c == 0) { r = 0; c = -1; }
                else if (r == 0 && c == -1) { r = -1; c = 0; }
                else if (r == -1 && c == 0) { r = 0; c = 1; }
            }
            i += r; j += c;
        }
        return ans;
    }
};