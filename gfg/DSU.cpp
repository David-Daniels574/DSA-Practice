#include <bits/stdc++.h>
using namespace std;


struct DisjointSet {
    vector<int> parent;
    vector<int> size;

    DisjointSet(int maxSize) {
        parent.resize(maxSize);
        size.resize(maxSize);
        for (int i = 0; i < maxSize; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        
        // path compression optimization
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

// Source - https://stackoverflow.com/a/68634345
// Posted by Appaji Chintimi, modified by community. See post 'Timeline' for change history
// Retrieved 2026-02-06, License - CC BY-SA 4.0

void solve() {
    int n;
    cin >> n;
    DisjointSet S(n);  // Initializing with maximum Size
    S.union_set(1, 2);
    S.union_set(3, 7);
    int parent = S.find_set(1);  // root of 1
}
