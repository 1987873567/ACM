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
	for(int i = 2026; i <= 9999; i++){
		std::string s = std::to_string(i);
		int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
		a *= 10;
		c *= 10;
		a += b;
		c += d;
		a += c;
		a *= a;
		if(a == i){
			int x = 0, cc = 0;
			while(x < i){
				x += cc * cc * cc;
				cc++;
			}
			if(x == i){
				std::cout << i << "\n";
				return;
			}
		}
	}
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