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
	std::vector<std::pair<i64, i64>> a, b;
	for(int i = 0; i < n; i++){
		i64 x, y;
		std::cin >> x >> y;
		if(x <= y){
			a.push_back({x, y});
		} else {
			b.push_back({x, y});
		}
	}
	i64 ans = 0, yu = 0;
	std::sort(all(a));
	for(auto &[x, y] : a){
		ans = std::max(ans, x - yu);
		yu += y - x;
	}
	std::sort(all(b), [&](auto &x, auto &y){
		return x.second > y.second;
	});
	for(auto &[x, y] : b){
		ans = std::max(ans, x - yu);
		yu += y - x;
	}
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}