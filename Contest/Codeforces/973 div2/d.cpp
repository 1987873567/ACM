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
	std::vector<i64> v(n);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	auto f = [&] (i64 x) -> std::pair<i64, i64> {
		i64 sum = 0, max = 0, min = 1e12;
		for(int i = 0; i < n; i++){
			i64 temp = v[i];
			if(temp > x)sum += temp - x, temp = x;
			else{
				i64 t = std::min(x - temp, sum);
				temp += t;
				sum -= t;
			}
			max = std::max(max, temp);
			min = std::min(min, temp);
		}
		return {(sum == 0), max - min};
	};

	i64 l = 0, r = 1e13;
	while(l + 1 != r){
		i64 mid = (l + r) >> 1;
		if (f(mid).first) {
			r = mid;
		} else {
			l = mid;
		}
	}
	i64 ans = 1e12;
	for(auto x : {l - 1, l , r , r + 1}){
		auto [flag, res] = f(x);
		if(flag){
			ans = std::min(ans, res);
		}
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