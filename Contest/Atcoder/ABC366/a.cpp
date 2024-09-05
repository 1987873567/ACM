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
	int n, a, b;
	std::cin >> n >> a >> b;
	int s = (n + 1) / 2;
	if(a >= s || b >= s) {
		YES;
	} else {
		NO;
	}
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