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
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);

        dp[0] = 1; // empty string
        dp[1] = 1; // first char already checked (not '0')

        for (int i = 2; i <= n; i++) {

            // take 1 digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // take 2 digits
            int two = stoi(s.substr(i - 2, 2));
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};