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
    int minMaxDifference(int num) {
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

        for (int i = 1; i < maxs.size(); i++){
            if (mins[i]==mins[0]){
                mins[i]='0';
            }
        }
        mins[0]='0';

    int a = stoi(maxs),b=stoi(mins);
    return a-b;
    }
};