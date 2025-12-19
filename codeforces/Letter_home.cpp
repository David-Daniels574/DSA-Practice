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

void solve(int n , int s , vector<int> arr) {
    int left = arr[0];
    int right = arr[n - 1];
    int steps = min(abs(s - left), abs(s - right)) + (right - left);
    cout << steps << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    int n,s,temp;
    for (int t = 1; t <= tc; t++) {
        cin>>n>>s;
        vector<int>arr(n);
        for (int i = 0; i < n; i++){
            cin>>temp;
            arr[i]=temp;
        }
        
        solve(n,s,arr);
    }
}