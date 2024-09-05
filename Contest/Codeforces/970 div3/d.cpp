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
	std::vector<int> v(n), vis(n), ans(n);
	for(int i = 0; i < n;i++) {
		std::cin >> v[i];
		v[i]--;
	}
	std::string col;
	std::cin >> col;
	int sum = 0;
	auto dfs = [&](auto &self, int x) -> void{
		if(!vis[v[x]]){
			vis[v[x]] = 1;
			sum += (col[v[x]] == '0');
			self(self,v[x]);
			ans[x] = sum; 
		}
	};
	for(int i = 0; i < n; i++){
		sum = 0;
		dfs(dfs,i);
	}
	for(int i = 0; i < n; i++){
		std::cout << ans[i] << " \n"[i == n - 1];
	}
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