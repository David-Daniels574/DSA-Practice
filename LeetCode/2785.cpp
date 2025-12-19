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
    bool is_vov(char c) {
        if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> v;
        for (int i = 0; i < s.size(); i++) {
            if (is_vov(s[i])) {
                v.push_back(s[i]);
            }
        }
        sort(v.begin(), v.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (is_vov(s[i])) {
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};