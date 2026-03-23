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
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        vector<vector<int>> ans;
        unordered_set<int> hold;
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] == true) {
                hold.insert(i);
            }
        }

        for (int i = 2; i <= n / 2; i++) {
            if (primes[i] == true) {
                if (hold.find(n - i) != hold.end()) {
                    ans.push_back({i, n - i});
                }
            }
        }

        return ans;
    }
};


//optimal
vector<vector<int>> findPrimePairs(int n) {
    vector<bool> prime(n + 1);
    for(int i = 2;i <= n; ++i)
        if(!prime[i]) 
            for(int j = 2 * i;j <= n; j += i)
                prime[j] = true;
    
    vector<vector<int>> ans;
    for(int i = 2;i + i <= n; ++i) {
        if(!prime[i]) {
            int key = n - i;
            if(key > 1 && !prime[key]) 
                ans.push_back({i, key});
        }
    }
    return ans;
}