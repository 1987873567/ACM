#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int v[1100][1100];
int r[1100],l[1100];
void solve() {
	int n;std::cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			std::cin >> v[i][j];
		}
	}
	int x, y;
	std::cin >> x >> y;
	for(int i = 1; i <= n; i++){
		r[i] = v[x][i];
		l[i] = v[i][y];
	}
	for(int i = 1; i <= n; i++){
		v[i][y] = r[i];
		v[x][i] = l[i];
	}
	v[x][y] = (r[x] + l[y] + 1) / 2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			std::cout << v[i][j] << " \n"[j == n];
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