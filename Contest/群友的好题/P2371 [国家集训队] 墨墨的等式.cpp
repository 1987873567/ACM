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
	i64 n, l, r;
	std::cin >> n >> l >> r;
	std::vector<i64> a;
	
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		if(x) a.push_back(x);
	}
	if(!a.size()){
		std::cout << "0\n";
		return;
	}
	std::sort(all(a));

	std::vector<std::vector<std::pair<i64, i64>>> g(a[0]);
	for(int i = 0; i < a[0]; i++){
		for(int j = 1; j < n; j++){
			g[i].push_back({(i + a[j]) % a[0], a[j]});
		}
	}
	std::vector<i64> vis(a[0]), dis(a[0], 1e18);
	dis[0] = 0;
	std::priority_queue<std::pair<i64, i64>> q;
	q.push({0, 0});
	while(q.size()){
		auto [d, x] = q.top();
		q.pop();

		if(vis[x])continue;
		vis[x] = 1;
		for(auto [y, w] : g[x]){
			if(dis[y] > dis[x] + w){
				dis[y] = dis[x] + w;
				q.push({-dis[y], y});
			}
		}
	}

	auto cal = [&](i64 x){
		i64 res = 0;
		for(int i = 0; i < a[0]; i++){
			if(dis[i] <= x){
				res += (x - dis[i]) / a[0] + 1;
			}
		}
		return res;
	};
	i64 ans = cal(r) - cal(l - 1);
	std::cout << ans << "\n";
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