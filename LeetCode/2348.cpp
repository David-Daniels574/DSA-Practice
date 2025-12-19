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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long temp=0;
        long long ans=0;
        for(int i=0 ; i<nums.size(); i++){
            if(nums[i]==0){
                temp++;
            }
            else{
                ans+=(temp+1)*temp/2;
                temp=0;
            }
        }
        if(temp!=0){
            ans+=(temp+1)*temp/2;
        }
    return ans;
    }
};