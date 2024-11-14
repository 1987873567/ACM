#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[2][2] = {0, 1, 1, 0};

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> mp(n, std::vector<int> (m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			std::cin >> mp[i][j];
		}
	}
	std::queue<std::array<int, 3>> q;
	q.push({0, 0, mp[0][0]});
	while(q.size()){
		auto [x, y, z] = q.front();
		q.pop();
		if(x == n - 1 && y == m - 1){
			YES;
			return;
		}
		for(int i = 0; i < 2; i++){
			int dx = d[i][0] + x, dy = d[i][1] + y;
			if(dx >= 0 && dx < n && dy < m && dy >= 0 && mp[dx][dy] == z){
				q.push({dx, dy , z});
			}
		}
	}
	NO;
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