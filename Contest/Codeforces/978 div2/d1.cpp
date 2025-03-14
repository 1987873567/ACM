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
	int n;
	std::cin >> n;
	int p = n;
	auto check = [&](int x, int y){
		int a, b;
		std::cout << "? " << x << " " << y << "\n";
		std::cout.flush();
		std::cin >> a;
		std::cout << "? " << y << " " << x << "\n";
		std::cout.flush();
		std::cin >> b;
		return a != b;
	};
	for(int i = 1; i <= n - 1; i += 2){
		if(check(i, i + 1)){
			p = i;
			break;
		}
	}
	if(p == n){
		std::cout << "! " << n << "\n";
	}else if(check(p, (p == 1 ? p + 2 : p - 1))){
		std::cout << "! " << p << "\n";
	}else{
		std::cout << "! " << p + 1 << "\n";
	}
	std::cout.flush();
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