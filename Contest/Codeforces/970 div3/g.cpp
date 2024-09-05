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
	std::vector<int> v(n);
	int d = 0;
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
		d = std::__gcd(d, v[i]);
	}
	if(n == 1) return std::cout << (v[0] >= k ? k - 1 : k) << "\n", void();

	int ans = 0;
	if (d == 1) {
		ans = n - 1 + k;
	} else {
		int t = std::min((k + d - 2) / (d - 1), n);
		ans = t + k - 1;
	}
	std::cout << ans << "\n";
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