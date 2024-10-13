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
	std::vector<std::string> v(n + 1, std::string(n, ' '));
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		v[i] = ' ' + v[i];
	}

	auto fun = [&](int x){
		std::string temp(n, ' ');
		for(int i = x; i <= n - x; i++){
			v[x][]
		}
	};

	for(int i = 1; i <= n / 2; i++){

	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			std::cout << v[i][j];
		}
		std::cout << "\n";
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

/*
123
456
789
*/