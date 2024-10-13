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
	std::string a, b;
	std::cin >> a >> b;
	a += ' ';
	b += ' ';
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			if(a[i + 1] == b[i] && a[i] == b[i + 1]){
				std::swap(a[i], a[i + 1]);
				ans++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		ans += (a[i] != b[i]);
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