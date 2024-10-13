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
	std::vector<std::array<int,2>> v(n * 2);
	for(int i = 0; i < n; i++){
		int l, r;
		std::cin >> l >> r;
		v[i] = {l, i};
		v[i + n] = {r, i};
	}

	std::sort(all(v), [&] (auto &a, auto &b){
		if(a[0] == b[0]){
			return a[1] > b[1];
		}
		return a[0] < b[0];
	});

	std::set<int> s;
	int ans = 0;
	for(auto [x, i] : v){
		if(s.count(i)){
			s.erase(i);
		}else{
			s.insert(i);
		}
		ans = std::max(ans, (int)s.size());
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