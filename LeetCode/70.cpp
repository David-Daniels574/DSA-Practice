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
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2 ;i<=n ;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    return dp[n];
    }
};