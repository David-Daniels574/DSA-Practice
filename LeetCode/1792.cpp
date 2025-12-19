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
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            double a = classes[i][0];
            double b = classes[i][1];
            pq.push(make_pair(((a + 1) / (b + 1)) - (a / b), i));
        }

        while (extraStudents > 0) {
            int index = pq.top().second;
            classes[index][0]++;
            classes[index][1]++;
            pq.pop();
            double a = classes[index][0];
            double b = classes[index][1];
            pq.push(make_pair(((a + 1) / (b + 1)) - (a / b), index));
            extraStudents--;
        }
        double ans = 0;
        for (int i = 0; i < classes.size(); i++) {
            double a = classes[i][0];
            double b = classes[i][1];
            ans += a / b;
        }

        return ans / classes.size();
    }
};