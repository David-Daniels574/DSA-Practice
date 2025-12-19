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
    int maximumLength(vector<int>& nums) {
        //both even/odd or 1 odd , 1 even
        //no order change 
        int even=0,odd=0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i]%2==0){
                even++;
            }
        }
        odd=nums.size()-even;
        int ans1=max(even,odd);
        int par = nums[0]%2,temp=1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i]%2!=par){
                par=nums[i]%2;
                temp++;
            }
        }
        return max(ans1,temp);
    }
};