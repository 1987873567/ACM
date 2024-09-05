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
	i64 n, a, b;
	std::cin >> n >> a >> b;
	std::vector<i64> v(n);
	i64 g = std::__gcd(a, b);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	std::sort(all(v));

	i64 x = ((v.back() + a + b) / g + 10) * g;
	std::vector<std::pair<i64, i64>> p(n * 2);

	for(int i = 0; i < n; i++){
		i64 temp = (x - v[i]) / g  * g + v[i], y;
		p[i * 2] = {temp, i};
		p[i * 2 + 1] = {temp + g, i};
	}

	std::sort(all(p));
	i64 ans = 1e14;
	std::vector<int> vis(n);
	int cnt = 0;
	for(int l = 0, r = -1; l < n; l++){
		while(r < 2 * n && cnt != n){
			r++;
			if(!vis[p[r].second])cnt++;
			vis[p[r].second]+=1;
		}
		if(cnt == n) ans = std::min(ans, p[r].first - p[l].first);
		if(--vis[p[l].second] == 0)cnt --;
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