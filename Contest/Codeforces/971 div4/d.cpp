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
	// std::vector<std::pair<int,int>> p(n);
	std::vector<std::vector<int>> mp(n + 10, std::vector<int> (2));
	for(int i = 0; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		mp[a][b] = 1;
	}
	i64 ans = 0;
	for(int i = 0; i <= n; i++){
		if (mp[i][0] && mp[i][1]) {
			ans += n - 2;
		}
		if(mp[i][0] && mp[i + 1][1] && mp[i + 2][0])ans ++;
		if(mp[i][1] && mp[i + 1][0] && mp[i + 2][1])ans ++;
	}
	std::cout << ans <<  "\n";
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