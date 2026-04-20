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
    vector<vector<int>> ans;

    void dfs(vector<int>& temp, int curr, vector<vector<int>>& graph, int n) {
        if (curr == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < graph[curr].size(); i++) {
            int nn = graph[curr][i];
            temp.push_back(nn);
            dfs(temp, nn, graph, n);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        vector<int> temp;
        temp.push_back(0);
        dfs(temp, 0, graph, n);
        return ans;
    }
};