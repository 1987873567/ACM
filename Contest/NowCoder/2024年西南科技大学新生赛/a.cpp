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
	int n, x, y;
	std::cin >> n >> x >> y;
	i64 a = 0, b = 0;
	std::vector<int> aa(n), bb(n);
	for(auto &i : aa) std::cin >> i;
	for(auto &i : bb) std::cin >> i;
	for(int i = 0; i < n; i++){
		b += (bb[i] > x ? -2 : 1);
		a += (aa[i] > y ? -2 : 1);
		a = std::max(a, 0ll);
		b = std::max(b, 0ll);
	}
	// std::cout << a << ' ' << b << "\n";
	if(a > b){
		std::cout << "zy\n";
	}else if(a < b){
		std::cout << "sdy\n";
	}else{
		std::cout << "none\n";
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