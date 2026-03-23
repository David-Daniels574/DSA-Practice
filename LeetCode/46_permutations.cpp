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
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& temp, unordered_set<int>& chosen) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (chosen.find(nums[i]) == chosen.end()) {
                temp.push_back(nums[i]);
                chosen.insert(nums[i]);

                solve(nums, temp, chosen);

                temp.pop_back();          // backtrack
                chosen.erase(nums[i]);    // backtrack
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        unordered_set<int> chosen;
        solve(nums, temp, chosen);
        return ans;
    }
};