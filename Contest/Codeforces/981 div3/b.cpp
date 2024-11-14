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
	std::vector<std::vector<int>> mp(n, std::vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> mp[i][j];
		}
	}
	auto up = [&](int x, int y){
		int res = 0;
		while(x < n && y < n){
			res = std::min(res, mp[x][y]);
			mp[x][y] = 100;
			x++, y++;
		}
		return -res;
	};
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mp[i][j] < 0){
				ans += up(i, j);
			}
		}
	}
	std::cout << ans << '\n';
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