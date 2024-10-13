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

	std::vector<i64> v(n + 1), dp(n + 1);
	std::vector<std::vector<i64>> g(n + 1);

	for(int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}
	dp = v;
	for (int i = 2, p; i <= n; i++) {
		std::cin >> p;
		g[p].push_back(i);
	}

	auto dfs = [&] (auto &dfs, int x) -> void{
		i64 z = 1e18;
		for (auto y : g[x]) {
			dfs(dfs, y);
			z = std::min(dp[y], z);
		}
		if(!g[x].size()){
			dp[x] = v[x];
			return ;
		}
		if (x == 1) {
			dp[x] += z;
			return;
		}
		if(v[x] < z) dp[x] = (v[x] + z) / 2;
		else dp[x] = z;
	};
	dfs(dfs, 1);
	std::cout << dp[1] << "\n"; 
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