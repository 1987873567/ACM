
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
	int n, m;
	std::cin >> n >> m;
	std::map<int, std::pair<std::string, std::string>> a;
	std::string s;
	int id = 0;
	std::map<std::string ,int > vis;
	for (int i = 1; i <= n; i ++) {
		std::cin >> s;
		if(!vis[s])a[++id].first = s,vis[s] = 1;
	}
	vis.clear();
	id = 0;
	for (int i = 1; i <= m; i++) {
		std::cin >> s;
		if(!vis[s])a[++id].second = s,vis[s] = 1;
	}
	vis.clear();
	for(auto &[i,j] : a){
		auto [x, y] = j;
		if(x.size() && !vis[x]){
			vis[x] = 1;
			std::cout << x << "\n";
		}
		if(y.size() && !vis[y]){
			vis[y] = 1;
			std::cout << y << "\n";
		}
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