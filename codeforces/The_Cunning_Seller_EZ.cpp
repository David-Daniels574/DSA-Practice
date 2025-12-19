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

long long power(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= base;
    }
    return res;
}

void solve(int n) {
    long long cost=0;
    int i=0;
    while(n>0){
        int dig=n%3;
        if(dig==1){
            cost += power(3, i + 1) + (long long)i * power(3, i - 1);
        }
        else if (dig == 2) {
            cost += 2 * (power(3, i + 1) + (long long)i * power(3, i - 1));
        }
    n /= 3;
    i++;
    }
    cout<<cost<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int a;
        cin>>a;
        solve(a);
    }
}