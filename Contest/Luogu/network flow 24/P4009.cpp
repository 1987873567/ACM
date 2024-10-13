#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
i64 mp[110][110];
i64 dis[110][110][11];
i64 n, K, A, B, C;
i64 ans = 1e18;
bool check(int x, int y) {
	return x < 1 || x > n || y < 1 || y > n;
}
void dfs(i64 x, i64 y, i64 k, i64 c){
	if(check(x, y)) return;
	if (k < 0 || c >= ans) return;
	k--;
	for (int i = k; i <= K; i++){
		if(dis[x][y][k] <= c)return;
	}
	dis[x][y][k] = c;
	if(x == n && y == n){ ans = std::min(ans, c); return;}
	int add = 0;
	if(mp[x][y]) add += A, k = K;
	if(!k) add += (A + C), k = K;
	dfs(x + 1, y, k , c + add);
	dfs(x, y + 1, k , c + add);
	dfs(x - 1, y, k , c + add + B);
	dfs(x, y - 1, k , c + add + B);
}

void solve() {

	std::cin >> n >> K >> A >> B >> C;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
			std::cin >> mp[i][j];
		}
	}

	memset(dis, 0x3f, sizeof dis);
	dfs(1, 1, K + 1, 0);
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