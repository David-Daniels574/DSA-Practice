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

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
The top view of a binary tree can be found using BFS. A queue stores each node
with its horizontal distance from the root, while a hashmap keeps track of the 
first node seen at each distance. During traversal, nodes at new horizontal 
distances are added to the map, and the minimum distance is tracked. After traversal,
the map’s values are transferred to a result array in order from leftmost to rightmost, 
ensuring that nodes closer to the root appear first in the top view.
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        // queue stores {node, horizontal distance}
        queue<pair<Node*, int>> q;
        map<int, int> mp;

        q.push({root, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};