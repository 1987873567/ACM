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
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n);

	for(int i = 0; i < n; i++){
		std::string s;
		std::cin >> s;
		p[i] = std::bitset<21>(s).to_ullong();
	}
	int k;
	std::cin >> k;
	std::vector<int> y(k); 
	for(int i = 0; i < k; i++){
		std::string s;
		std::cin >> s;
		y[i] = std::bitset<21>(s).to_ullong();
	}
	for(int i = 0; i < n; i++){
		int ans = 1e9;
		for(int j = 0; j < (1 << k); j++){
			int x = 0, res = 0;
			for(int w = 0; w < k; w++){
				if(j >> w & 1){
					x |= y[w];
					res++;
				}
			}
			if((x & p[i]) == p[i]) ans = std::min(ans, res);
		}
		if(ans == 1e9)ans = -1;
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