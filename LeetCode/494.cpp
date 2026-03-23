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
    int cnt=0;
    void solve(int curr , vector<int>& nums, int target, int index){
        if (curr==target && index==nums.size()){
            cnt++;
        }

        if(index==nums.size()){
            return;
        }
        solve(curr+nums[index],nums,target,index+1);
        solve(curr-nums[index],nums,target,index+1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0,nums,target,0);
        return cnt;
    }
};