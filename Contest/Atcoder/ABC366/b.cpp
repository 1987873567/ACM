#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	// std::vector<int> m(n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		m = std::max((int)v[i].size(), m);
		// m[i] = std::max((int)v[i].size(), m[std::max(i - 1, 0)]);
	}

	for (int j = 0; j < m; j++) {
		std::string temp = "";
		for (int i = n - 1; i >= 0 ; i--) {
			if(v[i].size() <= j)temp += "*";
			else temp += v[i][j];
		}
		while(temp.back() == '*')temp.pop_back();
		std::cout << temp << "\n";
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}