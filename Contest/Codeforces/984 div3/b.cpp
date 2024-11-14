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
	std::map<int, int> sum;
	for(int i = 0; i < k; i++){
		int b, c;
		std::cin >> b >> c;
		sum[b] += c;
	}
	int ans = 0;
	std::vector<std::pair<int, int>> t(all(sum));
	std::sort(all(t), [&](auto a, auto b){
		return a.second < b.second;
	});
	for(int i = t.size() - 1; i >= std::max((int)t.size() - n, 0); i--){
		ans += t[i].second;
	}
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}