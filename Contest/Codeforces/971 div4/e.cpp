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

	i64 l = 0, r = n + 1;
	auto cal = [&] (i64 x, i64 y) {
		return x * y + (y - 1) * y / 2;
	};
	while(l < r) {
		i64 ll = l + (r - l) / 3;
		i64 rr = r - (r - l) / 3;
		i64 x = std::abs(cal(k, ll) - cal(k + ll, n - ll));
		i64 y = std::abs(cal(k, rr) - cal(k + rr, n - rr));
		if(x <= y){
			r = rr - 1;
		} else {
			l = ll + 1;
		}
	}
	std::cout << std::abs(cal(k, l) - cal(k + l, n - l)) << "\n";
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