#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct point{
	i64 x, y;
	
};
ld dis(point a, point b){
		return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void solve() {
	int n;
	std::cin >> n;
	ld ans = 0;
	point o = {0, 0}, p = o;
	for(int i = 0; i < n; i++){
		point t;
		std::cin >> t.x >> t.y;
		ans += dis(p, t);
		p = t;
	}
	ans += dis(p, o);
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
    std::cout<<std::fixed<<std::setprecision(9);

    while (_--) {
        solve();
    }
    return 0;
}