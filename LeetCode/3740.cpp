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
    int minimumDistance(vector<int>& nums) {
        vector<pair<int,int>> arr;
        if(nums.size()<3){
            return -1;
        }

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int ans = INT_MAX;

        for (int i = 0; i < arr.size() - 2; i++) {
            if (arr[i].first == arr[i+1].first && arr[i+1].first == arr[i+2].first) {
                int d = abs(arr[i].second - arr[i+1].second) +
                        abs(arr[i+1].second - arr[i+2].second) +
                        abs(arr[i+2].second - arr[i].second);

                ans = min(ans, d);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};