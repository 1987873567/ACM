#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
struct DSU {
    std::vector<int> f, cnt;

    DSU(int n) {
        f.resize(n + 1);
        iota(all(f), 0);
    }

    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    void add(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            f[y] = x;
        }
    }
    bool s(int x, int y) { return find(x) == find(y); }
    int c(int x) { return cnt[find(x)]; }
};
void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::array<int, 2>> e(m + 1), vis(n + 1);
	std::vector<int> r(n + 1);
	std::vector<std::vector<std::array<int, 2>>> g(n + 1);
	for (auto &[i, j] : std::ranges::subrange(e.begin() + 1, e.end())) {
	    std::cin >> i >> j;
	    r[i]++;
	    r[j]++;
	}


	for (int i = 1; i <= m; i++) {
		auto [a, b] = e[i];
		if((r[a] == r[b] && a > b) || (r[a] > r[b])) std::swap(a, b);
		g[a].push_back({b, i});
	}

	DSU dsu(m);

	for (int i = 1; i <= n; i++) {
		for(auto [x, j] : g[i]) vis[x] = {i, j};

		for(auto [x, j] : g[i]) {
			for(auto [y, k] : g[x]) {
				if(vis[y][0] == i){
					dsu.add(k, j);
					dsu.add(j, vis[y][1]);
				}
			}
		}

	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(dsu.find(i) == i) ans++;
	}
	if(ans == 1) {
		YES;
	} else {
		NO;
	}
	// std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}