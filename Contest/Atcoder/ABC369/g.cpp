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
	std::vector<std::vector<std::array<i64, 2>>> g(n + 1);
	std::vector<i64> sum(n + 1), r(n + 1);
	for(int i = 1;i < n;i++){
		int a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
		r[b] ++;
		r[a]++;
	}
	auto dfs=[&](auto &self,int x, int f) ->void{
		for(auto [y, c] : g[x]){
			if(y != f){
				sum[y] = sum[x] + c;
				self(self,y,x);
			}
		}
	};
	dfs(dfs, 1 , -1);
	std::priority_queue<i64> q;
	for(int i = 2; i <= n; i++){
		if(r[i] == 1) q.push(sum[i] * 2);
	}
	i64 ans = 0;
	for(int i = 1; i < n; i++){
		if(q.size()){
			ans += q.top();
			q.pop();
		}
		std::cout << ans << "\n";
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