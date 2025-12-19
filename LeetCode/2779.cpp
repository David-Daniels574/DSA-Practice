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


//N^2
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int ans = 0, temp = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + k >= nums[j] - k) {
                    temp++;
                }
            }
            ans = max(ans, temp);
            temp = 1;
        }
        return ans;
    }
};


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int temp=0,ans=0;
        for (int i = 0; i < nums.size(); i++){
            auto it =upper_bound(nums.begin(), nums.end(), nums[i]+2*k);
            int loc = (it-nums.begin());
            temp=loc-i+1;
            ans=max(ans,temp);
        }
    return ans;
    }
};