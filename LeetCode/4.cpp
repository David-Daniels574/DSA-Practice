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

//BRUTE
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        vector<int>nums;
        int x=0,y=0;
        while(x<nums1.size() && y<nums2.size()){
            if(nums1[x]>=nums2[y]){
                nums.push_back(nums2[y]);
                y++;
            }
            else{
                nums.push_back(nums1[x]);
                x++;
            }
        }

        while(x<nums1.size()){
            nums.push_back(nums1[x]);
            x++;
        }
        while(y<nums2.size()){
            nums.push_back(nums2[y]);
            y++;
        }

        if(nums.size()%2==0){
            return (nums[(nums.size()/2)-1]+nums[nums.size()/2])/2.0;
        }
        return (double) nums[nums.size()/2];
    }
};

