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
	std::vector<int> v(n + 1), sum(n + 2);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		sum[i] += sum[i - 1]; 
		v[i] += sum[i];
		int s = n - i;
		int t = std::min(v[i], s);
		v[i] -= t;
		if(t){
			sum[i + 1]++;
			sum[i + 1 + t]--;
		}
	}
	for(int i = 1; i <= n; i++){
		std::cout << v[i] << " \n"[i == n - 1];
	}
}

int main() {
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