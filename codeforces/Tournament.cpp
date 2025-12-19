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


void solve(int n , int j , int k , vector<int> arr) {
    if (k == 0) {
        cout << "NO" << endl;
        return;
    }

    int num = arr[j - 1];  // strength of player j
    sort(arr.begin(), arr.end(), greater<int>());  // sort in descending order

    // Check if num is in the top k strengths
    for (int i = 0; i < k; i++) {
        if (arr[i] == num) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}








int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n,j,k;
        cin>>n>>j>>k;
        vector<int>arr(n);
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }
        
        solve(n,j,k,arr);
    }
}