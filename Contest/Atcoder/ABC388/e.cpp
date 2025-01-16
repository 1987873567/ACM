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
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	auto f = [&](int x){
		for(int i = 0; i < x; i++){
			if(v[i] * 2 > v[n - x + i])return 0;
		}
		return 1;
	};
	int l = 0, r = n / 2 + 1;
	while(l + 1 != r){
		int mid = (l + r) / 2;
		if(f(mid)){
			l = mid;
		} else {
			r = mid;
		}
	}
	std::cout << l << "\n";
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