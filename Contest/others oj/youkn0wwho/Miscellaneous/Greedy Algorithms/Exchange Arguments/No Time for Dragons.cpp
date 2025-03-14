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
	std::vector<std::pair<i64,i64>> v(n);
	for(int i = 0; i < n; i++){
		auto &[a, b] = v[i];
		std::cin >> a >> b;
	}
	std::sort(all(v),[&](auto &a, auto &b){
		if(a.first - a.second == b.first - b.second){
			return a.first > b.first;
		}
		return a.first - a.second > b.first - b.second;
	});
	i64 ans = 0, h = 0;
	for(int i = 0; i < n; i++){
		auto &[a, b] = v[i];
		if(h < a){
			ans += (a - h);
			h = a - b;
		} else {
			h -= b;
		}
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