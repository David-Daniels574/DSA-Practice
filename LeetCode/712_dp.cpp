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
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        int sum=0;
        for (int i = 0; i < s1.size(); i++){
            sum+=(int)s1[i];
            dp[0][i+1]=sum;
        }

        sum=0;
        for (int i = 0; i < s2.size(); i++){
            sum+=(int)s2[i];
            dp[i+1][0]=sum;
        }
        
        for (int i = 1; i < dp.size(); i++){
            for (int j = 1; j < dp[i].size(); j++){
                
                if (s1[j]==s2[i]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                }
                
            }  
        }

    return dp[n][m];
    }
};