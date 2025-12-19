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
    bool isPowerOfFour(int n) {
       if(n<=0)
                return false;
            int x = log(n)/log(4);
            return pow(4,x)==n || pow(4,x+1)==n; 
    }
};