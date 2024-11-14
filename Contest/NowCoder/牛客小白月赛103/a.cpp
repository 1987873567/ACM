#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "no\n"
#define YES std::cout << "yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::map<int, int> c;
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		c[x]++;
	}
	for(auto [a, b] : c){
		if(b >= 3){
			YES;
			std::cout << a * 3 << "\n";
			return;
		}
	}
	NO;
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