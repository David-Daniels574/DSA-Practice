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
    int longestOnes(vector<int>& nums, int k) {
        
        int ans=0,temp=0,temp_k=0;
        int l=0;
        for (int r = 0; r < nums.size(); r++){
            if (nums[r]==1){
                temp++;
            }
            else{
                if (temp_k==k){
                    
                    while (nums[l]==0){
                        l++;
                        temp_k--;
                        temp--;
                    }    
                }
                temp++;
                temp_k++;
            }
        ans=max(ans,temp);
        }
    return ans;
    }
};