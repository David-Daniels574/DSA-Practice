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
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int temp = k;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                r++;
            } else {
                if (temp == 0) {
                    while (nums[l] == 1) {
                        l++;
                    }
                    l++;
                    temp++;
                }
                temp--;
                r++;
            }
            ans = max(r - l, ans);
        }
        return ans;
    }
};

//optimal
int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int zeros = 0;
    int ans = 0;

    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] == 0) zeros++;

        while (zeros > k) {
            if (nums[l] == 0) zeros--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}