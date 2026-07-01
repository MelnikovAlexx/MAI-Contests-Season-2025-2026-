#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int parent[MAXN], rg[MAXN];

void make_set(int v) {
    parent[v] = v;
    rg[v] = 1;
}

int get(int v) {
    if (parent[v] == v) return v;
    else return parent[v] = get(parent[v]);
}

void unite(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;
    if (rg[a] > rg[b])
        swap(a, b);
    parent[a] = b;
    rg[b] += rg[a];
}

struct Point{
    int x, y;
};

double triangle_area(Point& a, Point& b, Point& c) {
    return 0.5 * ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

struct Edge{
    int u, v, c;
}; 

vector <Point> points;
vector <Point> cities;
vector <pair <int, int> > rivers;
vector <Edge> edges;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    points.resize(m);
    cities.resize(n);
    rivers.resize(k);
    for (int i = 0; i < m; i++)
        cin >> points[i].x >> points[i].y;
    for (int i = 0; i < k; i++) {
        cin >> rivers[i].first >> rivers[i].second;
        rivers[i].first--; rivers[i].second--;
    }
    for (int i = 0; i < MAXN; i++) {
        parent[i] = 0;
        rg[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> cities[i].x >> cities[i].y;
        make_set(i);
    }

    edges.clear();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (auto &[r1, r2] : rivers) {
                Point a = cities[i], b = cities[j], c = points[r1], d = points[r2];
                if (min(a.x, b.x) <= max(c.x, d.x) && max(a.x, b.x) >= min(c.x, d.x) 
                && min(a.y, b.y) <= max(c.y, d.y) && max(a.y, b.y) >= min(c.y, d.y)) {
                    if (triangle_area(a, b, c) * triangle_area(a, b, d) <= 0 && triangle_area(c, d, a) * triangle_area(c, d, b) <= 0) {
                        cnt++;
                    }
                }
            }
            edges.push_back({i, j, cnt});
        }
    }

    sort(edges.begin(), edges.end(), [](Edge &l, Edge &r){
        return l.c < r.c;
    });

    int ans = 0;
    for (auto &[u, v, c] : edges) {
        if (get(u) != get(v)) {
            ans += c;
            unite(u, v);
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}