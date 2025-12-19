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
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int i=0 ; i<arr.size(); i++){
            if(arr[i]%2!=0){
                cnt++;
                if(cnt==3){
                    return true;
                }
            }
            else{
                cnt=0;
            }
        }
    return false;
    }
};