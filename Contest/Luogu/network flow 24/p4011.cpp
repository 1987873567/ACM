#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
i64 mp[20][20][4], dis[20][20][2050], key[20][20];
void solve() {
	int n, m, p;
	std::cin >> n >> m >> p;
	int K;
	std::cin >> K;

	for(int i = 0; i < K; i++){
		int x1, x2, y1, y2, g;
		std::cin >> x1 >> y1 >> x2 >> y2 >> g;
		if(!g) g = -1;
		int x = x1 - x2, y = y1 - y2;
		x = -x, y = -y;
		for(int j = 0; j < 4; j++){
			if(x == d[j][0] && y == d[j][1]){
				mp[x1][y1][j] = g;
				mp[x2][y2][(j + 2) % 4] = g;
			}
		}	
	}

	int s;
	std::cin >> s;
	for(int i = 0; i < s; i++){
		int x, y, g;
		std::cin >> x >> y >> g;
		key[x][y] |= (1ll << g);
	}

	memset(dis, 0x3f, sizeof dis);
	std::priority_queue<std::array<i64, 4>> q;
	dis[1][1][0] = 0;
	q.push({0, 1, 1, 0});

	while(q.size()){
		auto [di, x, y, k] = q.top();
		q.pop();

		for(int i = 0; i < 4; i++){
			i64 dx = x + d[i][0], dy = y + d[i][1], dk = k;
			if(dx >= 1 && dy >= 1 && dx <= n && dy <= m){

				if(mp[x][y][i] == 0){

					if(key[dx][dy]) dk |= (key[dx][dy]);

					if(dis[dx][dy][dk] > dis[x][y][k] + 1){
						dis[dx][dy][dk] = dis[x][y][k] + 1;
						q.push({-dis[dx][dy][dk], dx, dy, dk});
					}
				}

				if (mp[x][y][i] > 0 && ((dk >> mp[x][y][i]) & 1)) {

					if(key[dx][dy]) dk |= (key[dx][dy]);

					if(dis[dx][dy][dk] > dis[x][y][k] + 1){
						dis[dx][dy][dk] = dis[x][y][k] + 1;
						q.push({-dis[dx][dy][dk], dx, dy, dk});
					}

				}
			}
		}
	}

	i64 ans = 1e18;
	for(int i = 0; i <= 2050; i++){
		ans = std::min(ans, dis[n][m][i]);
	}

	if(ans >= 1e14) ans = -1;
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