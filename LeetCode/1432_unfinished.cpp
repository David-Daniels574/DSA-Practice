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

void solve() {
}

class Solution {
public:
    int maxDiff(int num) {
        string maxs = to_string(num);
        string mins=maxs;
        int replacer;
        //for max
        for (int i = 0; i < maxs.size(); i++){
            if (maxs[i]=='9'){
                continue;
            }
            else{
                replacer=maxs[i];
                break;
            }
        }

        for (int i = 0; i < maxs.size(); i++){
            if (maxs[i]==replacer){
                maxs[i]='9';
            }
        }
        cout<<maxs<<endl;
        
        int rep_0=1;
        for (int i = 1; i < mins.size(); i++){
            if (mins[i]=='1'){
                continue;
            }
            else{
                replacer=mins[i];
                if (replacer==mins[0]){
                    rep_0=0;
                }
                break;
            }
        }
        
        for (int i = 0; i < maxs.size(); i++){
            if (mins[i]==replacer){
                if (rep_0==1){
                    maxs[i]='0';
                }
                else{
                    maxs[i]='1';
                }
            }
        }

        cout<<mins<<endl;
    int a = stoi(maxs),b=stoi(mins);
    return a-b;
    }
};