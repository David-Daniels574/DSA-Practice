#include <iostream>
#include <vector>

using namespace std;

class LazySegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        // 0-based indexing for tree nodes
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            // If not a leaf node, push down to children
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int L, int R, int val) {
        propagate(node, start, end);
        
        // Out of bounds
        if (start > R || end < L) return;
        
        // Fully within bounds
        if (L <= start && end <= R) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        
        // Partial overlap
        int mid = start + (end - start) / 2;
        updateRange(2 * node + 1, start, mid, L, R, val);
        updateRange(2 * node + 2, mid + 1, end, L, R, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryRange(int node, int start, int end, int L, int R) {
        propagate(node, start, end);
        
        // Out of bounds
        if (start > R || end < L) return 0;
        
        // Fully within bounds
        if (L <= start && end <= R) return tree[node];
        
        // Partial overlap
        int mid = start + (end - start) / 2;
        return queryRange(2 * node + 1, start, mid, L, R) + 
               queryRange(2 * node + 2, mid + 1, end, L, R);
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        if (n > 0) {
            build(arr, 0, 0, n - 1);
        }
    }

    // Public API wrappers
    void update(int L, int R, int val) {
        updateRange(0, 0, n - 1, L, R, val);
    }

    int query(int L, int R) {
        return queryRange(0, 0, n - 1, L, R);
    }
};