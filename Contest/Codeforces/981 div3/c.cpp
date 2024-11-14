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
	std::vector<int> v(n), b(n);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	b[0] = v[0];
	b[n - 1] = v[n - 1];
	for(int i = 1, j = n - 2; i < j; i++, j--){
		if(v[i] == b[i - 1]){
			b[i] = v[j];
			b[j] = v[i];
		}else{
			if(v[j] == b[j + 1]){
				b[i] = v[j];
				b[j] = v[i];
			} else {
				b[i] = v[i];
				b[j] = v[j];
			}
		}
	}
	if(n & 1){
		b[n / 2] = v[n / 2];
	}
	int ans = 0;
	for(int i = 1; i < n; i++){
		ans += (b[i] == b[i - 1]);
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