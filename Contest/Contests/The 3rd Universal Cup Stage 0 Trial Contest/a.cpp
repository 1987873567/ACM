#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

// void db(){
// 	int n;
// 	std::cin >> n;
// 	std::vector<std::pair<int,int>> v(n);
// 	for(auto &[a, b] : v){
// 		std::cin >> a >> b;
// 	}
// 	i64 ans = 1e18;
// 	for(int i = 0; i <= (1ll << n); i++){
// 		i64 a = 0, b = 0;
// 		for(int j = 0; j < n; j++){
// 			if((i >> j) & 1){
// 				a += v[j].first;
// 			} else {
// 				b += v[j].second;
// 			}
// 		}
// 		// std::cout << a << " " << b << '\n';
// 		ans = std::min(ans, std::max(a, b));
// 	}
// 	std::cout << ans << "\n";
// }

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int,int>> v(n);
	int ans = 1e9;
	for(auto &[a, b] : v){
		std::cin >> a >> b;
	}
	for(int t = 0; t < 1000000; t++){
		std::shuffle(all(v), Rand);
		int sa = 0, sb = 0, ssa = 0, ssb = 0;
		for(int i = 0; i < n; i++){
			auto [a, b] = v[i];
			if(sa + a > sb + b) sb += b;
			else sa += a;
			if(ssa + a >= ssb + b) ssb += b;
			else ssa += a;
		}
		ans = std::min({ans, std::max(sa, sb), std::max(ssa, ssb)});
	}
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
        // db();
    }
    return 0;
}