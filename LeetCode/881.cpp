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
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());

      int l=0,r=people.size()-1;
      int ans=0;
      while(r>=l){
        if(people[r]+people[l]>limit){
            r--;
        }
        else{
            r--;
            l++;
        }
        ans++;
      }
    return ans;  
    }
};