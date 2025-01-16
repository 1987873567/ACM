#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()
#define int long long
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, m, sx, sy;
	std::cin >> n >> m >> sx >> sy;
	std::vector<std::array<int, 3>> x(n), y(n);
	std::vector<int> xs(n + 1), ys(n + 1);
	for(int i = 0; i < n; i++){
		int X, Y;
		std::cin >> X >> Y;
		x[i] = {X, Y, i};
		y[i] = {X, Y, i};
	}
	std::sort(all(x));
	std::sort(all(y),[&](auto &a, auto &b){
		if(a[1] == b[1]){
			return a[0] < b[0];
		}
		return a[1] < b[1];
	});
	for(int i = 0; i < m; i++){
		char d;
		int c;
		std::cin >> d >> c;

		if(d == 'U'){
			std::array<int, 3> temp = {sx, (int)-1e18, (int)-1e18};
			auto L = std::lower_bound(all(x), temp);
			temp = {sx, (int)1e18, (int)1e18};
			auto R = std::upper_bound(all(x), temp);
			temp = {sx, sy, 0};
			auto l = std::lower_bound(L, R, temp, [&](auto &a, auto &b){
				return a[1] < b[1];
			}) - x.begin();
			temp = {sx, sy + c, 0};
			auto r = std::upper_bound(L, R, temp, [&](auto &a, auto &b){
				return a[1] < b[1];
			}) - x.begin();
			xs[l] ++;
			xs[r + 1]--;
		} else if (d == 'D'){
			std::array<int, 3> temp = {sx, (int)-1e18, (int)-1e18};
			auto L = std::lower_bound(all(x), temp);
			temp = {sx, (int)1e18, (int)1e18};
			auto R = std::upper_bound(all(x), temp);
			temp = {sx, sy - c, 0};
			auto l = std::lower_bound(L, R, temp, [&](auto &a, auto &b){
				return a[1] < b[1];
			}) - x.begin();
			temp = {sx, sy, 0};
			auto r = std::upper_bound(L, R, temp, [&](auto &a, auto &b){
				return a[1] < b[1];
			}) - x.begin();
			xs[l] ++;
			xs[r + 1]--;
		} else if (d == 'L'){
			std::array<int, 3> temp = {sy, (int)-1e18, (int)-1e18};
			auto L = std::lower_bound(all(y), temp);
			temp = {sy, (int)1e18, (int)1e18};
			auto R = std::upper_bound(all(y), temp);
			temp = {sx, sy, 0};
			auto l = std::lower_bound(L, R, temp, [&](auto &a, auto &b){
				return a[1] < b[1];
			}) - y.begin();
			temp = {sx, sy + c, 0};
			auto r = std::upper_bound(L, R, temp, [&](auto &a, auto &b){
				return a[1] < b[1];
			}) - y.begin();
			ys[l] ++;
			ys[r + 1]--;
		} else if (d == 'R'){
			auto L = std::lower_bound(all(y), std::make_pair(sx, -1e18));
			auto R = std::upper_bound(all(y), std::make_pair(sx, 1e18));
			auto l = std::lower_bound(L, R, std::make_pair(sx, sy), [&](auto &a, auto &b){
				return a[0] < b[0];
			}) - y.begin();
			auto r = std::upper_bound(L, R, std::make_pair(sx + c, sy), [&](auto &a, auto &b){
				return a[0] < b[0];
			}) - y.begin();
			ys[l] ++;
			ys[r + 1]--;
		}
	}
	std::set<int> ans;
	for(int i = 1; i < n; i++){
		xs[i] += xs[i - 1];
		ys[i] += ys[i - 1];
	}
	for(int i = 1; i < n; i++){
		if(xs[i]){
			ans.insert(x[i].second)
		}
	}
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}