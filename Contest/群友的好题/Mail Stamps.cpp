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
	std::vector<std::array<int,2>> v(n);
	std::vector<int> vv;

	for(int i = 0; i < n; i++){
		std::cin >> v[i][0] >> v[i][1];
		vv.push_back(v[i][0]);
		vv.push_back(v[i][1]);
	}
	std::sort(all(vv));
	vv.erase(std::unique(all(vv)), vv.end());
	std::vector<std::vector<std::array<int, 2>>> g(n * 2);
	std::unordered_map<int, int> id;
	for(int i = 0; i < n; i++){
		auto [a, b] = v[i];
		a = std::lower_bound(all(vv), a) - vv.begin();
		b = std::lower_bound(all(vv), b) - vv.begin();
		id[a] = v[i][0];
		id[b] = v[i][1];

		g[a].push_back({b, i});
		g[b].push_back({a, i});
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