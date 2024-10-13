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
	i64 n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::array<i64, 3>>> v(m + 1);
	for(i64 i = 1; i <= m; i++){
		i64 x, p, q;
		std::cin >> x >> p >> q;
		if(!q){
			v[i].push_back({0, x, p});
		} else {
			v[q].push_back({1, x, p});
		}
	}

	std::vector<i64> dp(n + 1);
	for(i64 i = 1; i <= m; i++){
		std::sort(all(v[i]));
	}
	for(i64 i = 1; i <= m; i++){
		for(auto [q, x, p] : v[i]){
			i64 y = v[i][0][1];
			if(q) y += x;
			for(i64 j = n; j >= y; j--){
				dp[j] = std::max(dp[j], dp[j - x] + p);
			}
		}
	}
	std::cout << dp[n]	<< '\n';
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