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
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n;
    int bfs(vector<vector<int>>& grid, int i, int j, int id) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = id;

        int size = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = id;
                    q.push({nx, ny});
                    size++;
                }
            }
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> mp;

        int id = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mp[id] = bfs(grid, i, j, id);
                    id++;
                }
            }
        }

        int ans = 0;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int>seen;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                            grid[nx][ny] > 1 && seen.count(grid[nx][ny]) == 0) {
                            temp += mp[grid[nx][ny]];
                            seen.insert(grid[nx][ny]);
                        }
                    }
                    temp++;
                    ans = max(ans, temp);
                    temp = 0;
                }
            }
        }
        if (ans == 0)
            return n * n;
        return ans;
    }
};
