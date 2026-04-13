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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(n, 0);
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int u = i;
                int v = adj[u][j];
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < adj[u].size(); i++) {
                indegree[adj[u][i]]--;
                if (indegree[adj[u][i]] == 0) {
                    q.push(adj[u][i]);
                }
            }
        }

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] != 0) {
                return false;
            }
        }

        return true;
    }
};