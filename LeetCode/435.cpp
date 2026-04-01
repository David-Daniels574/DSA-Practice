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

//Basically , this Q is meeting rooms , but we need max no of rooms with no problem
//so greedy on end time

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int size = intervals.size();
        int prev = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prev) {
                cnt++;
                prev = intervals[i][1];
            } else {
                continue;
            }
        }
        return size - cnt;
    }
};