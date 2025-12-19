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



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n;
        cin>>n;
        vector<int>cnt(4,0);
        for (int i = 0; i < n; i++){
            cnt[i%4]++;
        }
        int pairs = min(cnt[0],cnt[3])+min(cnt[1],cnt[2]);
        int remain = n-2*pairs;

        if(remain==0){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
        
    }
}