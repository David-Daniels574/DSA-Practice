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
    int maximumDifference(vector<int>& nums) {
        int curr_min=nums[0],ans=-1;

        for (int i = 1; i < nums.size(); i++){
            if(curr_min<nums[i]){
                ans=max(ans,abs(curr_min-nums[i]));
            }
            curr_min=min(curr_min,nums[i]);
        }
        return ans;
    }
};