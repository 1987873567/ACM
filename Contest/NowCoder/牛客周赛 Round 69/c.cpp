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
	i64 n, h;
	std::cin >> n >> h;
	i64 x, y, z;
	for(int i = 0; i < n; i++){
		std::cin >> x >> y >> z;
        if(x == 0 && y == 0){
            std::cout << "0 0 " << h << "\n";
            continue;
        }
        i64 c = 2 * h - z;
        i64 a = x, b = y;
        if(z != 0){
            a = x * c / z;
            b = y * c / z;
        }
        
        i64 g = std::__gcd(a, std::__gcd(b, c));
        a /= g;
        b /= g;
        c /= g;
        std::cout << a << " " << b << ' ' << c << '\n';
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