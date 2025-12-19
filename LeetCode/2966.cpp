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

void solve() {
}

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i + 2] - nums[i] <= k) {
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
                i += 2;
            } else {
                return {};
            }
        }

        return ans;
    }
};