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
	std::vector<std::vector<int>> g(n + 1);


	for (int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		a -= 1;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	std::vector<int> vis(n + 1);
	int sum = 0;
	auto dfs = [&](auto &dfs, int x) -> void {
		if(!vis[x])vis[x] = 1,sum++;

		for(auto y : g[x]){
			if(!vis[y])
			dfs(dfs, y);
		} 
	};
	dfs(dfs, 0);
	if(sum == n + 1){
		std::cout << "1\n";
	}else{
		std::cout << "0\n";
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