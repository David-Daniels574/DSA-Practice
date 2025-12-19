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

//ME solving (same logic , slow hashmap)
class Solution {
public:
    bool mapsEqual(const unordered_map<int, int>& a,
                   const unordered_map<int, int>& b) {
        if (a.size() != b.size())
            return false;
        for (auto& [key, value] : a) {
            auto it = b.find(key);
            if (it == b.end() || it->second != value)
                return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        int t = n;
        if (n == 1)
            return true;

        unordered_map<int, int> mp;
        if (n == 0) {
            mp[0]++;
        } else {
            while (n > 0) {
                int digit = n % 10;
                mp[digit]++;
                n /= 10;
            }
        }

        n = t;
        int digits = (n == 0) ? 1 : floor(log10(abs(n))) + 1;

        vector<int> s{0,  4,  7,  10, 14, 17, 20, 24, 27,
                      30, 34, 37, 40, 44, 47, 50, 54};

        for (int i = s[digits - 2]; i < s[digits]; i++) {
            unordered_map<int, int> mp1;
            long long temp = pow(2, i);
            if (temp == 0) {
                mp1[0]++;
            } else {
                while (temp > 0) {
                    int digit = temp % 10;
                    mp1[digit]++;
                    temp /= 10;
                }
            }

            if (mapsEqual(mp, mp1)) {
                return true;
            }
        }

        return false;
    }
};

//smart sorting solution 
// note 1<<i means power 2
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto countDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i) == target) return true;
        }
        return false;
    }
};
