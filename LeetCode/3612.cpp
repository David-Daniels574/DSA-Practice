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
    string processStr(string s) {
        string ans="";
        for(int i=0 ; i<s.size(); i++){
            char curr=s[i];
            if(curr=='*'){
                if(ans.empty()){
                    continue;
                }
                ans.pop_back();
            }
            else if(curr=='#'){
                ans+=ans;
            }
            else if(curr=='%'){
                reverse(ans.begin(),ans.end());
            }
            else{
                ans+=curr;
            }
        }
    return ans;
    }
};