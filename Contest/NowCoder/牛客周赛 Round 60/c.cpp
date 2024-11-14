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
	std::vector<i64> rmax(n + 1), rmin(n + 1, 1e9), lmin(n + 1, 1e9), lmax(n + 1);
	for(int i = 0; i < m; i++){
		i64 a, b;
		std::cin >> a >> b;
		rmax[a] = std::max(rmax[a], b);
		lmax[b] = std::max(lmax[b], a);
		rmin[a] = std::min(rmin[a], b);
		lmin[b] = std::min(lmin[b], a);
	}
	i64 ans = 0;
	for(int i = 1; i <= n;i++){
		ans = std::max(ans, rmax[i] - rmin[i]);
		ans = std::max(ans, lmax[i] - lmin[i]);
	}
	std::cout << ans << "\n";
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