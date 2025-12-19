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
    string largestGoodInteger(string num) {
        int max1 = INT_MIN;
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i - 1] == num[i] && num[i] == num[i + 1]) {
                max1 = max(num[i] - '0', max1);
            }
        }

        if (max1 == INT_MIN) {
            return "";
        }
        string ans(3, (char)('0' + max1));
        return ans;
    }
};