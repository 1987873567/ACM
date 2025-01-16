#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		std::cin >> b[i];
	}
	int A = 0, B = 1e9, C = 0;
	for(int i = 0; i < n; i++){
		if(a[i] < b[i]){
			A = std::max(A, b[i] - a[i]);
			C++;
		} else {
			B = std::min(B, a[i] - b[i]);
		}
	}
	if(C <= 1 && A <= B){
		YES;
	} else {
		NO;
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}