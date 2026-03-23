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
    long long maximumSubsequenceCount(string text, string pattern) {
        long long tot1 = 0, tot0 = 0, base = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == pattern[0]) {
                tot0++;
            }
            if (text[i] == pattern[1]) {
                base += tot0;
                tot1++;
            }
        }
        if (pattern[0] == pattern[1]) {
            return base;
        }
        return max(base + tot1, base + tot0);
    }
};
