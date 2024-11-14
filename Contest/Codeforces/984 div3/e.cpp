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
	int n, k, q;
	std::cin >> n >> k >> q;
	std::vector<std::vector<int>> a(n + 1, std::vector<int>(k + 1)), b(k + 1, std::vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			std::cin >> a[i][j];
		}
	}
	for(int i = 1; i <= k; i++){
		int x = 0;
		for(int j = 1; j <= n; j++){
			x |= a[j][i];
			b[i][j] = x;
		}
	}
	// for(int i = 1; i <= k; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		std::cout << b[i][j] << " \n"[j == n];
	// 	}
	// }
	while(q--){
		int m;
		std::cin >> m;
		int l = 1, r = n;
		int ans = 1;
		while(m--){
			int x, y;
			char op;
			std::cin >> x >> op >> y;
			int tl = 1, tr = n;
			if(op == '<'){
				auto p = std::lower_bound(all(b[x]), y) - b[x].begin();
				while(p > 0 && b[x][p] >= y) p--;
				if(p == 0) ans = 0;
				tr = p; 
			} else {
				auto p = std::upper_bound(all(b[x]), y) - b[x].begin();
				if(p > n) ans = 0;
				tl = p; 
			}
			if(tl > r || tr < l) ans = 0;
			else {
				l = std::max(l, tl);
				r = std::min(r, tr);
			}
		}
		if(ans) ans = l;
		else ans = -1;
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