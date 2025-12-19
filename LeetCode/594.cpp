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
    int findLHS(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans=0,temp=0;
       int number=0;
       for (int i = 0; i < nums.size(); i++){
            int j=i+1;
            if (nums[i]==number){
                continue;
            }
            
            while(nums[j]==nums[i] || nums[j]==nums[i]+1){
                j++;
                temp++;
            }
            if (temp>ans){
                number=nums[i];
                ans=temp;
            }
            temp=0;
       }
    return ans;
    }
};