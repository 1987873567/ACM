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
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n);
	for(int &i : v)std::cin >> i;
	int ans = 0;
	auto check = [&](int x){
		int res = 0;
		for(int i = x, j = x + k - 1; j < n && i < j; i++, j--){
			if(v[i] != v[j]) res++;
			if(res > 1)return 0;
		}
		return res;
	};
	for(int i = 0; i < n; i++){
		if(check(i))ans++;
	}
	std::cout << ans << "\n";
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