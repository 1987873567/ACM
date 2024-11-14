#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
i64 a[3][3] = {{1, 1, 1},{1, 2, 1}, {1, 1, 0}};
int cal() {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
         - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
         + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

i64 n;

void solve() {
	std::cin >> n;
	a[2][2] = n + 1;
	
	if(n == -1){
		std::swap(a[1][1], a[1][2]);
		a[2][1] = 2;
		a[2][2] = 1;
	}
	// std::cout << cal() << "\n";
	for(i64 i = 0; i < 3; i++){
		for(i64 j = 0; j < 3; j++){
			std::cout << a[i][j] << " \n"[j == 2];
		}
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