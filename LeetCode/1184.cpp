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
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        if(start>destination){
            swap(start,destination);
        }
        int sum=accumulate(distance.begin(),distance.end(),0);
        int clock=0;
        for(int i=start ; i<destination; i++){
            clock+=distance[i];
        }
        return min(clock, sum-clock);
    }
};