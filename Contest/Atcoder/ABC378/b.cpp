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
	std::vector<std::pair<i64, i64>> c(n);
	for(i64 i = 0; i < n; i++){
		i64 r, q;
		std::cin >> q >> r;
		c[i] = {q, r}; 
	}
	i64 q;
	std::cin >> q;
	while(q--){
		i64 p, d;
		std::cin >> p >> d;
		p--;
		i64 l = 0, r = 1e9;
		while(l + 1 != r){
			i64 m = (l + r) >> 1;
			i64 x = m * c[p].first + c[p].second;
			if(x <= d){
				l = m;
			} else {
				r = m;
			}
		}
		for(auto i : {l - 1, l, r, r + 1}){
			if(l < 0)continue;
			i64 x = i * c[p].first + c[p].second;
			if(x >= d){
				std::cout << x << "\n";
				break;
			}
		}
		// std::cout <<  << "\n";
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