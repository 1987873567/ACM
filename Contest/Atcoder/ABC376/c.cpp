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
	std::vector<int> a(n);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	std::multiset<int> b;
	for(int i = 0, x; i < n - 1; i++){
		std::cin >> x;
		b.insert(x);
	}
	std::sort(all(a));
	int ans = 0, cnt = 0;
	for(int i = n - 1; i >= 0; i--){
		auto pos = b.lower_bound(a[i]);
		if(pos == b.end()){cnt++, ans = a[i];continue;}
		b.erase(pos);
	}
	if(cnt > 1){
		std::cout << "-1\n";
	} else {
		std::cout << ans << "\n";
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