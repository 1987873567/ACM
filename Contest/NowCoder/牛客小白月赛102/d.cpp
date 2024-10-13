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
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<i64> a(n);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}

	std::vector<std::vector<i64>> g(n);
	for(int i = 0; i < m; i++){
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	std::vector<std::array<i64, 2>> dis(n, std::array<i64, 2>{(i64)1e18, (i64)1e18});
	std::vector<bool> vis(n);

	dis[0][0] = 0;
	dis[0][1] = a[0];

	std::priority_queue<std::array<i64, 3>> q;//dis, id, s;
	q.push({0, 0, 0});

	while(q.size()){
		auto [d, id, s] = q.top();
		q.pop();

		if(vis[id]) continue;
		vis[id] = 1;

		for(auto i : g[id]){
			if(s == k){
				if(dis[i][1] > dis[id][0] + a[i])
			}else{

			}
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