#include <bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, m, l;
	std::cin >> n >> m >> l;
	std::vector<i64> a(n), b(m), ib(m);
	for(auto &i : a) std::cin >> i;
	for(auto &i : b) std::cin >> i;
	std::set<std::pair<int, int>> vis;

	std::iota(all(ib), 0);

	std::sort(all(ib), [&](int x, int y) {
		return b[x] > b[y]; 
	});

	for(int i = 0; i < l; i++){
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		vis.insert({a, b});
	}
	using pii = std::pair<i64, i64>;
	i64 ans = 0;
	std::priority_queue<pii> q;
	std::vector<int> cur(n);
	for(int i = 0; i < n; i++){
		q.push({a[i] + b[ib[cur[i]]], i});
	}
	while(1){
		auto [x, i] = q.top();q.pop();
		int j = cur[i];
		if(!vis.count({i, ib[j]})){
			std::cout << x << "\n";
			return;
		}
		cur[i] ++ ;
		if(cur[i] != m) q.push({a[i] + b[ib[cur[i]]], i});
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