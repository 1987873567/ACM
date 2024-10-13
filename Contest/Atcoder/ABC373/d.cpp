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
	int n, m;
	std::cin >> n >> m;
	std::vector<i64> ans(n + 1), vis(n + 1);
	std::vector<std::vector<std::array<i64, 2>>> g(n + 1);
	for(int i = 0; i < m; i++){
		i64 a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, -c});
	}

	auto dfs = [&](auto &dfs, i64 x) -> void{
		for(auto [y, w] : g[x]){
			if(!vis[y]){
				ans[y] = ans[x] + w;
				vis[y] = 1;
				dfs(dfs, y);
			}
		}
	};

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(dfs, i);
		}
	}

	for(int i = 1; i <= n; i++){
		std::cout << ans[i] << " \n"[i == n];
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}