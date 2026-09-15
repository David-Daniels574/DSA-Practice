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

    int check(vector<int>& weights, int cap){
        int sum=0,cnt=0;
        for (int i = 0; i < weights.size(); i++){
            sum+=weights[i];
            if (sum>cap){
                cnt++;
                sum=weights[i];
            }
        }
        cnt++;
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        int mid=0;
        while (h>=l){
            mid=l+(h-l)/2;
            int ret=check(weights,mid);
            
            //good case , i actually need less days
            if (ret < days){
                h=mid-1;
            }
            else{
                l=mid;
            }
            
        }
    return mid;
    }
};