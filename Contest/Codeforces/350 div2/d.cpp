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
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n), b(n);
	for (auto &i : a) std::cin >> i;
	for (auto &i : b) std::cin >> i;
	i64 l = 0, r = 2e9 + 1;
	auto f = [&](i64 x) {
		i64 res = k;
		for(int i = 0; i < n && res >= 0; i++){
			res -= std::max(0ll, 1ll * a[i] * x - 1ll * b[i]);
		}
		return res >= 0;
	};
	while (l + 1 != r) {
		i64 mid = (l + r) >> 1;
		if (f(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	std::cout << l << "\n";
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