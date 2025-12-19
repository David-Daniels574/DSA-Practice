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
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i][0] == '.' && logs[i][1] == '.' && ans > 0) {
                ans--;
                cout << logs[i] << endl;
            } else if (logs[i][0] != '.') {
                ans++;
            }
        }
        if (ans < 0) {
            return 0;
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                ans = max(ans - 1, 0);
            } else if (logs[i] != "./") {
                ans++;
            }
        }
        return ans;
    }
};