#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
/*
13 8 5 4
3 4 2 1

10 4 3 3
3 4 2 1


*/
void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> v(n + 2), a(n + 2), sum(n + 2), ans(n + 2), x(n + 2);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		std::cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		int l = i, r = n + 1;
		while(l + 1 != r){
			int m = (l + r) / 2;
			i64 t = sum[m] - sum[i - 1];
			if(t <= v[i]){
				l = m;
			} else {
				r = m;
			}
		}
		i64 pos = l;
		if(sum[pos] - sum[i - 1] <= v[i]){
			x[i] += 1;
			x[pos + 1] --;
			ans[pos + 1] += std::min(a[pos + 1], v[i] - sum[pos] + sum[i - 1]);
		} else {
			ans[pos] += std::min(v[i], a[pos]);
		}
	}
	for(int i = 1; i <= n; i++){
		x[i] += x[i - 1];
		ans[i] += x[i] * a[i];
		std::cout << ans[i] << " \n"[i == n];
	}
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}