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
    string rle(string s) {

        if (s.size() == 1) {
            return "11";
        }
        string ans = "";
        int cnt = 1;
        char prev = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (prev == s[i]) {
                cnt++;
            } else {
                ans += to_string(cnt);
                ans += prev;
                prev = s[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += prev;
        return ans;
    }

    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            cout << s << endl;
            s = rle(s);
        }
        return s;
    }
};