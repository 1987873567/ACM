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
	std::vector<i64> v(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
	}
	int flag = 1;
	int pos = -1;
	for(int i = 2; i <= n; i++){
		if(v[i] && v[i - 1] && abs(v[i] - v[i - 1]) > 1) flag = 0;
		if(v[i]) pos = i;
	}
	if(flag){
		std::cout << "0\n";
		return;
	}
	const int mod = 1e9 + 7;

	std::vector<i64> dp(n + 1, 1);
	i64 ans = 0;
	if(pos == -1){

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