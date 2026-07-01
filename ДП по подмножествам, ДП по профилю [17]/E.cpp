#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector <int> sum;

bool can(int hp) {
    vector<int> min_d(1 << n, 1e18);
        int all = (1 << n) - 1;
        min_d[all] = 0;
        queue<int> q;
        q.push(all);

        while (!q.empty()) {
            int mask = q.front();
            q.pop();
            int cur_d = min_d[mask];

            for (int i = 0; i < n; i++) {
                int k1 = (1 << i), k2 = (1 << ((i - 2 + n) % n)), k3 = (1 << ((i + 2) % n));
                int new_mask = mask & ~(k1 | k2 | k3);
                int new_d = cur_d + sum[new_mask];

                if (new_d < hp && new_d < min_d[new_mask]) {
                    min_d[new_mask] = new_d;
                    q.push(new_mask);
                }
            }
        }

        return min_d[0] <= hp;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector <int> d(n);
    for (auto &x : d) cin >> x;
    sum.resize(1 << n, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) 
                sum[mask] += d[i];
        }
    }
    int l = 0, r = 1e18;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid)) 
            r = mid;
        else
            l = mid;
    }

    cout << r;
}