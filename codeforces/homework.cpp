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

void solve(int a , int b , string x , string y , string z) {

    deque <char> dq;
    for (int i = 0; i < x.size(); i++){
        dq.push_back(x[i]);
    }

    for (int i = 0; i < y.size(); i++){
        if (z[i]=='V'){
            dq.emplace_front(y[i]);
        }
        else{
            dq.emplace_back(y[i]);
        }
    }
    
    for (char val : dq) {
        cout << val;
    }
    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    int tc = 1;
    cin >> tc;
    cin.ignore();    
    for (int t = 1; t <= tc; t++) {
        int a,b;
        string x,y,z;
        cin >> a;
        cin.ignore();
        getline(cin, x);
        cin >> b;
        cin.ignore(); 
        getline(cin, y);
        getline(cin, z);  
        solve(a,b,x,y,z);
    }
    
    return 0;
}