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
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> a(n), vis(n + 1), b(m);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		std::cin >> b[i];
	}
	int pre = 0;
	for(int i = 0, x; i < m; i++){
		x = b[i];
		if(vis[x]){
			continue;
		}
		if(pre < n && a[pre] == x){
			vis[a[pre]] = 1;
			pre++;
			continue;
		}
		std::cout << "TIDAK\n";
		return;
	}
	std::cout << "YA\n";

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