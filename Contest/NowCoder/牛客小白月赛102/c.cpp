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
	i64 n, x;
	std::cin >> n >> x;
	std::vector<int> v(n);
	std::multiset<std::pair<i64,i64>> a, b;
	i64 sum = 0;
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
		sum += v[i];
		a.insert({1e4 - v[i], i});
		b.insert({abs(-1e4 - v[i]), i});
	}
	std::vector<int> vis(n);
	int ans = 0;
	while(sum != x){
		if (sum > x) {
			i64 t = sum - x;
			auto p = b.lower_bound({t, -1});
			if(p == b.end()) p = std::prev(p);
			while(b.size() && vis[p->second]){
				b.erase(p);
				p = b.lower_bound({t, -1});
				if(p == b.end()) p = std::prev(p);
			}
			vis[p->second] = 1;
			sum -= std::min(p->first, t);
		} else if(sum < x) {
			i64 t = x - sum;
			auto p = a.lower_bound({t, -1});
			if(p == a.end()) p = std::prev(p);
			while(a.size() && vis[p->second]){
				a.erase(p);
				p = a.lower_bound({t, -1});
				if(p == a.end()) p = std::prev(p);
			}
			vis[p->second] = 1;
			sum += std::min(p->first, t);
		}
		ans++;
	}
	std::cout << ans << "\n";
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