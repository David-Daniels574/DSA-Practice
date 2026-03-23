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
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += reward2[i];
        }

        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(reward1[i] - reward2[i]);
        }

        while (k--) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
