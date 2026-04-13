#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree; // Segment tree array
    vector<int> arr;  // Original array
    int n;            // Size of array

    /*
        Build function:
        - Recursively constructs the segment tree
        - node: current index in segment tree
        - start, end: range in original array represented by this node
    */
    void build(int node, int start, int end) {
        // Base case: leaf node (single element)
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        // Avoid overflow using this formula
        int mid = start + (end - start) / 2;

        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        // Recursively build left and right subtrees
        build(leftChild, start, mid);
        build(rightChild, mid + 1, end);

        // Merge step (here: sum)
        tree[node] = tree[leftChild] + tree[rightChild];
    }

    /*
        Query helper:
        - Returns sum in range [L, R]
        - node: current segment tree index
        - start, end: current segment range
    */
    int query(int node, int start, int end, int L, int R) {
        // 1. No Overlap → return neutral element (0 for sum)
        if (start > R || end < L) {
            return 0;
        }

        // 2. Total Overlap → return stored value
        if (L <= start && end <= R) {
            return tree[node];
        }

        // 3. Partial Overlap → split into children
        int mid = start + (end - start) / 2;

        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = query(leftChild, start, mid, L, R);
        int rightSum = query(rightChild, mid + 1, end, L, R);

        return leftSum + rightSum;
    }

    /*
        Update helper:
        - Updates value at index idx to val
        - Then fixes tree while backtracking
    */
    void update(int node, int start, int end, int idx, int val) {
        // Base case: reached leaf node
        if (start == end) {
            arr[idx] = val;     // Update original array
            tree[node] = val;   // Update segment tree
            return;
        }

        int mid = start + (end - start) / 2;

        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        // Decide which subtree to go
        if (idx <= mid) {
            update(leftChild, start, mid, idx, val);
        } else {
            update(rightChild, mid + 1, end, idx, val);
        }

        // Recalculate current node after update
        tree[node] = tree[leftChild] + tree[rightChild];
    }

public:
    /*
        Constructor:
        - Initializes tree and builds it
    */
    SegmentTree(const vector<int>& inputArr) {
        arr = inputArr;
        n = arr.size();

        // Allocate enough space (safe size = 4*n)
        tree.resize(4 * n);

        // Build only if array is not empty
        if (n > 0) {
            build(0, 0, n - 1);
        }
    }

    /*
        Public query API:
        - User only provides L and R
    */
    int query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }

    /*
        Public update API:
        - Update index idx with value val
    */
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
};

/*
    Example usage
*/
int main() {
    vector<int> arr = {5,3,1,4,7,2};

    // 1. Build the segment tree
    SegmentTree st(arr);

    // 2. Query range 
    cout << "Sum of range [1, 3]: " << st.query(1, 4) << endl;

    // 3. Update index 
    st.update(5, 4);

    // 4. Query again
    cout << "Sum after update: " << st.query(1, 5) << endl;

    return 0;
}