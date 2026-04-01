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
    vector<int> searchRange(vector<int>& nums, int target) {
    
    int left = 0, right = nums.size();  // [left, right)

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int a=left;
    if(nums.empty() || a>=nums.size() || nums[a]!=target){
        return {-1,-1};
    }

    left = 0, right = nums.size();  // [left, right)

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int b=left-1;
    
    return {a,b};
    }
};