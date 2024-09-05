
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
	int a, b;
	std::cin >> a >> b;
	if(((b & 1) && (a % 2 == 0 && a))||(a % 2 == 0 && b % 2 ==0)){
		YES;
	} else{
		NO;
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