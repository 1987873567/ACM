#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> dis(2, std::vector<int> (n, 1e9));
	std::string mp[2];
	std::cin >> mp[0] >> mp[1];
	std::priority_queue<std::array<int,3>> q;
	q.push({0, 0, 0});
	dis[0][0] = 0;
	while(q.size()){
		auto [_, x, y] = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + d[i][0], dy = y + d[i][1];
			if (dx >= 0 && dx < 2 && dy >= 0 && dy < n) {
				if(mp[dx][dy] == '<') dy--;
				if(mp[dx][dy] == '>') dy++;
				assert(dy < n);
				if (dis[dx][dy] > dis[x][y] + 1) {
					dis[dx][dy] = dis[x][y] + 1;
					q.push({-dis[dx][dy], dx, dy});
				}
			}
		}
	}
	int ans = dis[1][n - 1];
	if(ans >= 1e7) ans = 0;
	else ans = 1;
	if(ans) {
		YES;
	} else {
		NO;
	}
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