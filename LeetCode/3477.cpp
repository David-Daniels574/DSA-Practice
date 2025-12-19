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
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;

        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j]) {
                    ans++;
                    baskets[j] = 0;
                    break;
                }
            }
        }
        return fruits.size() - ans;
    }
};