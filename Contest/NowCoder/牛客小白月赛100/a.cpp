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
	i64 a, b, c;
	std::cin >> a >> b >> c;
	
	auto f =[](i64 x, i64 y, i64 z) -> bool{
		std::vector<i64> v{x, y, z};
		std::sort(all(v));
		return v[0] + v[1] > v[2];
	};
	int flag = f(a * 2, b ,c);
	flag |= f(a , b * 2 ,c);
	flag |= f(a , b ,c * 2);
	if(flag){
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
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}