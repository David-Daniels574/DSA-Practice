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


//multimap
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp1;
        multimap<int, char> mp2;

        for (char c : s) {
            mp1[c]++;
        }

        for (auto& [ch, freq] : mp1) {
            mp2.insert({freq, ch});
        }

        string ans = "";

        // go reverse to get ascending
        for (auto it = mp2.rbegin(); it != mp2.rend(); it++) {
            int freq = it->first;
            char ch = it->second;

            ans += string(freq, ch);
        }

        return ans;
    }
};
