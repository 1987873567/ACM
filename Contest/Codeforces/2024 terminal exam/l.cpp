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
	int x1,y1,x2,y2;
	char ch;
	std::cin >> x1 >> ch >> y1 >> x2 >> ch >> y2;
	int m = x2 * 60 + y2 - x1 * 60 - y1;
	m /= 2;
	int x = x1 + m / 60;
	int y = y1 + m % 60;
	x += (y / 60);
	y %= 60;
	// std::cout << x1 << " " << m << "\n";
	std::cout << std::fixed << std::setw(2) << std::setfill('0') << x << ":" << std::fixed << std::setw(2) << std::setfill('0') << y << "\n";	
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}