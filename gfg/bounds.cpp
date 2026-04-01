#include <iostream>
#include <vector>
using namespace std;

// returns index of first element >= target
int lowerBound(vector<int>& v, int target) {
    int left = 0, right = v.size();  // [left, right)

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;  // may return v.size() if not found
}

// returns index of first element > target
int upperBound(vector<int>& v, int target) {
    int left = 0, right = v.size();  // [left, right)

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (v[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> v = {1, 2, 4, 4, 4, 5, 7};

    int target = 4;

    int lb = lowerBound(v, target);
    int ub = upperBound(v, target);

    cout << "Lower Bound index: " << lb << endl;
    cout << "Upper Bound index: " << ub << endl;

    return 0;
}