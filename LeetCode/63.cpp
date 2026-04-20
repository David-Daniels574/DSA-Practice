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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == -1) {
                break;
            }
            obstacleGrid[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == -1) {
                break;
            }
            obstacleGrid[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == -1) {
                    continue;
                }
                int a = obstacleGrid[i - 1][j];
                int b = obstacleGrid[i][j - 1];
                if (a == -1 && b == -1) {
                    obstacleGrid[i][j] = 0;
                } else if (a == -1) {
                    obstacleGrid[i][j] = b;
                } else if (b == -1) {
                    obstacleGrid[i][j] = a;
                } else {
                    obstacleGrid[i][j] = a + b;
                }
            }
        }
        if (obstacleGrid[m - 1][n - 1] == -1) {
            return 0;
        }
        return obstacleGrid[m - 1][n - 1];
    }
};