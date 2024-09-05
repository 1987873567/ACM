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
	std::vector<std::array<i64, 4>> e(m);
	std::vector<std::vector<int>> mp(n, std::vector<int>(n, 1e9));
	std::vector<int> id(n);
	std::iota(all(id), 0);
	for(int i = 0; i < m; i++){
		int a, b, c;
		std::cin >> a >> b >> c;
		e[i] = {a - 1, b - 1, c, i};
		mp[a - 1][b - 1] = mp[b - 1][a - 1] = std::min(mp[a - 1][b - 1], c);
	}
	
	auto cal = [&] (){
		int k = 0;
		std::cin >> k;
		std::set<int> s;
		for(int i = 0, x; i < k; i++){
			std::cin >> x;
			s.insert(x - 1);
		}
		std::vector<i64> dis(n,1e14),vis(n);
		dis[0] = 0;
		for(int i = 0; i < n - 1; i++){
			int x = 0;
			for (int j = 0; j < n; j++){
				if(!vis[j] && (x == 0 || dis[j] < dis[x])) x = j;
			}
		}

	};
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