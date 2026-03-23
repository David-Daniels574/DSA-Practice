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
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; // base case: prefix sum 0 exists once

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }
            // the number exist
            mp[sum]++;
        }
        return count;
    }
};
