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
	if(n == 1) return std::cout << "1\n1\n", void();
	if(k == n || k == 1) return std::cout << "-1\n", void();
	if(k & 1){
		std::cout << "3\n";
		std::cout << "1 " << k - 1 << " " <<  k + 2 << "\n"; 
	} else {
		std::cout << "3\n";
		std::cout << "1 " << k << " " <<  k + 1 << "\n"; 
	}
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