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
	i64 n, k;
	std::cin >> n >> k;
	std::vector<int> p(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> p[i];
	}
	std::map<std::vector<int>, int> vis;
	// k = std::min(k, 30ll);
	auto print = [n](auto &v){
		for(int i = 1; i <= n; i++){
			std::cout << v[i] << " \n"[i == n];
		}
	};
	int cnt = 0;
	while(k--){
		if(vis.count(p)){
			break;
		}
		vis[p] = cnt++;
		auto q = p;
		for(int i = 1; i <= n; i++){
			q[i] = p[p[i]];
		}
		std::swap(q, p);
	}
	if(k != -1){
		int s = vis[p];
		int len = cnt - s;
		k++;
		k %= len;
		for(auto &[v, id] : vis){
			if(id == s + k){
				print(v);
				return;
			}
		}
	}else{
		print(p);
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