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
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0.0;
        for (int num : nums) {
            pq.push(static_cast<double>(num));
            sum += static_cast<double>(num);
        }

        double half = sum / 2.0;
        int operations = 0;
        double currentSum = sum;

        while (currentSum > half) {
            double top = pq.top();
            pq.pop();
            double halved = top / 2.0;
            pq.push(halved);
            currentSum -= halved;
            operations++;
        }

        return operations;
    }
};