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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);

        for(int i=0 ; i<bookings.size(); i++){
            int l = bookings[i][0] - 1;  
            int r = bookings[i][1];
            int seats = bookings[i][2];
            ans[l] += seats;
            if (r < n)
                ans[r] -= seats;
        }
        for(int i=1 ;i<ans.size(); i++){
            ans[i]+=ans[i-1];
        }

    return ans;
    }
};