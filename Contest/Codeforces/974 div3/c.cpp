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
	i64 n;
	std::cin >> n;
	std::vector<i64> v(n);
	i64 sum = 0;
	for(i64 i = 0; i < n; i++){
		std::cin >> v[i];
		sum += v[i];
	}
	if(n <= 2){
		std::cout << "-1\n";
		return;
	}
	std::sort(all(v));
	i64 half = n / 2 + 1;
	auto check = [&](i64 x){
		i64 avg = (sum + x + 2 * n - 1)  / (n * 2);
		i64 ans = 0;
		for(i64 i = 0; i < n - 1; i++){
			if(v[i] < avg) ans++;
			else break;
		}
		return ans >= half;
	};
	i64 l = 0, r = 1e12;
	while(l + 1 != r){
		i64 m = (l + r) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	// std::cout << l << "\n";
	for(auto i : {l - 1, l , r , r + 1}) {
		if(i >= 0 && check(i)){
			std::cout << i << "\n";
			return;
		}
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