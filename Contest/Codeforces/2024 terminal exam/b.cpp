#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> v(n + 1), vis(n + 1), min(n + 1), id(n + 1);
	std::vector<std::vector<int>> g(n + 1);

	for(int i = 1; i <= n; i++) {
		std::cin >> v[i];
		min[i] = v[i];
		id[i] = i;
	}
	for(int i = 2; i <= n; i++){
		int a, b;
		std::cin >> a >> b;
		min[b] = min[a] = std::min(min[a], v[b]);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	std::sort(all(id), [&] (int x, int y) {return v[x] < v[y];});
	i64 ans = 0;
	for(int i = 1; i <= n; i++){
		if(vis[id[i]]) continue;
		ans += std::min(v[id[i]], min[id[i]]);
		
	}
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