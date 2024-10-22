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
	std::vector<std::pair<int,int>> v(n);
	for(int i = 0; i < n; i++){
		std::cin >> v[i].first >> v[i].second;
	}
	int ans = 0;
	std::sort(all(v),[&](auto a, auto b){
		if(a.second == b.second)return a.first < b.first;
		return a.second < b.second; 
	});
	std::multiset<int> s;
	for(int i = 0; i < k; i++){
		s.insert(0);
	}
	for(auto [a, b] : v){
		auto p = s.upper_bound(a);
		if(p == s.begin()) continue;
		s.erase(--p);
		ans++;
		s.insert(b);
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