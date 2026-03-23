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
    int integerReplacement(int n) {
        int ans = 0;
        if (n == 1) {
            return ans;
        }
        long long temp = n;
        while (temp > 1) {
            if (temp % 2 == 0) {
                temp >>= 1;
                ans++;
            } else {
                if (temp == 3 || temp % 4 == 1) {
                    temp--;
                } else {
                    temp++;
                }
                ans++;
            }
        }

        return ans;
    }
};

