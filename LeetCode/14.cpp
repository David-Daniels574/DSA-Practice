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
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int m=INT_MAX;
        for (int i = 0; i < strs.size(); i++){
            m=min(m,(int)strs[i].size());
        }
        char c;
        for (int i = 0; i < m; i++){
            c=strs[0][i];
            for (int j = 0; j < strs.size(); j++){
                if (strs[j][i]!=c){
                    return ans;
                }
                
            }
            ans+=c;
        }
    return ans;
    }
};