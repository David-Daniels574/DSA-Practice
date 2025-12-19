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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // bitset<32> binary(n);
        // string str = binary.to_string();
        // vector<int> ans;
        // reverse(str.begin(),str.end());
        // cout<<str;
        vector<int> ans, power;
        int binaryNum[32];
        int i = 0;
        while (n > 0) {
            binaryNum[i] = n % 2;
            if (binaryNum[i] == 1) {
                power.push_back(pow(2, i));
            }
            n = n / 2;
            i++;
        }
        long long temp = 1;
        for (int i = 0; i < queries.size(); i++) {
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                temp =(temp* power[j])%1000000007;
            }
            ans.push_back(temp);
            temp = 1;
        }

        return ans;
    }
};