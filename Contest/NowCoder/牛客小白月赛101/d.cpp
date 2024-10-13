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
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> v(n + 1), sum(n + 1), x(n + 2);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		sum[i] += sum[i - 1] + v[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			i64 y = sum[j] - sum[i - 1];
			i64 t = std::sqrt(y);
			if(t * t == y) x[i]++, x[j + 1]--;
		}
	}
	for(int i = 1; i <= n; i++){
		x[i] += x[i - 1];
	}
	while(q--){
		int pos;
		std::cin >> pos;
		std::cout << x[pos] << "\n";
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