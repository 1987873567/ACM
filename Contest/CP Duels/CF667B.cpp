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
	std::vector<i64> v(n);
	i64 sum = 0;
	for(i64 i = 0; i < n; i++){
		std::cin >> v[i];
		sum += v[i];
	}
	std::sort(all(v));
	i64 ans = 1e18, x = 0;
	for(i64 i = 0; i < n; i++){
		sum -= v[i];
		x += v[i];
		ans = std::min(ans, std::abs(sum - x) + 1);
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