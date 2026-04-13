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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<vector<pair<int,int>>> adj(n + 1);

        // build graph
        for (int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({w, v});
        }

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [dis, u] = pq.top();
            pq.pop();

            if (dis > dist[u]) continue;  // optimization

            for (auto &it : adj[u]){
                int nd = it.first;
                int v = it.second;

                if(dist[u] + nd < dist[v]){
                    dist[v] = dist[u] + nd;
                    pq.push({dist[v], v});
                }
            }  
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};