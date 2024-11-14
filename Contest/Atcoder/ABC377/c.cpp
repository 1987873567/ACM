#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
std::set<std::pair<i64, i64>> vis;
i64 n, m;
bool check(i64 x, i64 y){
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
void add(i64 x, i64 y){
	vis.insert({x, y});
	if(check(x + 2, y + 1))
	    vis.insert({x + 2, y + 1});
	if(check(x + 1, y + 2))
	    vis.insert({x + 1, y + 2});
	if(check(x - 1, y + 2))
	    vis.insert({x - 1, y + 2});
	if(check(x - 2, y + 1))
	    vis.insert({x - 2, y + 1});
	if(check(x - 2, y - 1))
	    vis.insert({x - 2, y - 1});
	if(check(x - 1, y - 2))
	    vis.insert({x - 1, y - 2});
	if(check(x + 1, y - 2))
	    vis.insert({x + 1, y - 2});
	if(check(x + 2, y - 1))
	    vis.insert({x + 2, y - 1});
}
void solve() {
	std::cin >> n >> m;
	i64 ans = n * n;
	while(m--){
		i64 x, y;
		std::cin >> x >> y;
		add(x, y);
	}
	ans -= vis.size();
	std::cout << ans << '\n';
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