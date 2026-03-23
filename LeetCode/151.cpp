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
    string reverseWords(string s) {
        vector<string> temp;
        string t = "";
        int i = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        while (i < s.size()) {
            if (s[i] == ' ') {
                if (t.size() != 0) {
                    temp.push_back(t);
                    t.clear();
                }
            } else {
                t += s[i];
            }
            i++;
        }
        if (!t.empty()) {
            temp.push_back(t);
        }
        reverse(temp.begin(), temp.end());
        string ans = "";
        for (int i = 0; i < temp.size(); i++) {
            if (i > 0) {
                ans += " ";
            }
            ans += temp[i];
        }
        return ans;
    }
};