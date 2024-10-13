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
	std::vector<i64> v(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
	}
	i64 ans = 1e16;
	auto f = [&] (i64 x)->std::pair<i64,i64>{
		i64 res = 0, cnt = 1, s = 0;
		for(int i = 1; i <= n;){
			if(s + v[i] > x){
				cnt ++;
				if(s == 0) s = v[i++];
				res = std::max(res, s);
				s = 0;
			} else {
				s += v[i++];
			}
		}
		res = std::max(res, s);
		return {cnt, res};
	};
	i64 l = 0 , r = 1e15;
	while(l + 1 != r) {
		i64 m = (l + r) >> 1;
		if(f(m).first <= k){
			r = m;
		} else {
			l = m;
		}
	}
	for(auto i : {l , l - 1, r , r + 1}) {
		auto [x, y] = f(i);
		if(x <= k)
		ans = std::min(ans, y);
	}
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