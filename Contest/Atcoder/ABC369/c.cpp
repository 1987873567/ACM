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
	i64 ans = n + n - 1;
	std::vector<int> v(n + 1);
	for(int i = 1; i <= n; i++)std::cin >> v[i];
	for(int l = 1, r = 2; l <= n; l++){
		i64 d = -1;
		while(r <= n && (d == -1 || (d == v[r] - v[r - 1]))){
			d = v[r] - v[r - 1];
			r ++;
		}
		i64 len = r - l;
		ans += len * (len + 1) / 2;
		ans -= 2 * len - 1;
		if(r - l > 1)l = r - 2;
		else l = r - 1;
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