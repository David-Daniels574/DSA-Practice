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
    int maxArea(vector<int>& height) {
        int ans = 0;
        int ht = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                ht = min(height[i], height[j]);
                ans = max(ht * (j - i), ans);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, ht;
        int l = 0, r = height.size() - 1;

        while (r > l) {
            if (height[r] > height[l]) {
                ht = min(height[l], height[r]);
                ans = max(ht * (r - l), ans);
                l++;
            } else {
                ht = min(height[l], height[r]);
                ans = max(ht * (r - l), ans);
                r--;
            }
        }
        return ans;
    }
};