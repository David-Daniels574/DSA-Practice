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

void solve(ll n) {

    vector<ll>ans;
    ll power=1;
    for (int i = 0; i <=19; i++){
        power*=10;
        long long denom=1+power;
        if (denom>n){
            break;
        }
        if (n%denom==0){
            ll x=n/denom;
            ll y=x*power;
            ans.push_back(x);
        } 
    }

    if (ans.empty())
    {
        cout<<"0"<<endl;
        return;
    }
    
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        ll a;
        cin>>a;
        solve(a);
    }
}