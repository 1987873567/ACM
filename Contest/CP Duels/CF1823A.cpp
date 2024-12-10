#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n);
	//枚举1
	for(int i = 0; i <= n; i++){
		int c1 = i * (i - 1) / 2;
		int c2 = (n - i) * (n - i - 1) / 2;
		// std::cout << c1 << " " << c2 << " " << i << "\n";
		if(c1 + c2 == k){
			YES;
			for(int j = 0; j < i; j++){
				std::cout << "1 ";
			}
			for(int j = 0; j < (n - i); j++){
				std::cout << "-1 ";
			}
			std::cout << "\n";
			return;
		}
	}
	NO;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}