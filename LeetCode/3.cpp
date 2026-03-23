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
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, r = 0;

        if (s.size() == 1) {
            return 1;
        }
        char curr = s[0];
        for (int i = 1; i < s.size(); i++) {
            curr = s[i];
            for (int j = l; j <= r; j++) {
                if (curr == s[j]) {
                    l = j + 1;
                }
            }
            r++;
            ans = max(ans, r + 1 - l);
        }
        return ans;
    }
};