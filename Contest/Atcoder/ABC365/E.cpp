#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	i64 n;
	std::cin >> n;
	i64 ans = 0;
	std::vector<i64> v(n + 1);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> v[i];
		ans -= v[i];
		v[i] ^= v[i - 1];
	}
	for (i64 i = 0; i <= 30; i++) {
		i64 a = 0, b = 0;
		for (i64 j = 0; j <= n; j++) {
			if ((v[j] >> i) & 1) {
				ans += b * (1ll << i);
				a++;
			} else {
				ans += a * (1ll << i);
				b++;
			}
		}
	}
	std::cout << ans << " \n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}