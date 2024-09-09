#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int h, w, q;
	std::cin >> h >> w >> q;
	std::vector<std::vector<int>> mp(h, std::vector<int> (w));
	std::vector<std::vector<std::array<int, 4>>> sikp(h, std::vector<std::array<int, 4>> (w));
	std::vector<int> p(1);
	auto dfs = [&](auto &dfs, int x, int y, int dir)->void {
		if(mp[x][y]){
			int dx = x + d[dir][0];
			int dy = y + d[dir][1];
			if(dx >= h || dy >= w || dx < 0 || dy < 0) return;
			if(sikp[x][y][dir]){
				dx = x + d[dir][0] * sikp[x][y][dir];
				dy = y + d[dir][1] * sikp[x][y][dir];
				p.push_back(sikp[x][y][dir]);
				dfs(dfs, dx, dy, dir);
				p[0] += p.back();
				sikp[x][y][dir] = p[0];
				p.pop_back();
			}else {
				p.push_back(1);
				dfs(dfs, dx, dy, dir);
				p[0] += p.back();
				sikp[x][y][dir] = p[0];
				p.pop_back();
			}
			
		} else {
			mp[x][y] = 1;
			return;
		}
	};
	while(q--){
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		if(!mp[x][y]) {
			mp[x][y] = 1; continue;
		}
		for(int i = 0; i < 4; i++){
			p[0] = 0;
			dfs(dfs, x, y, i);
		}
	}
	int ans = 0;
	for(int i = 0 ; i < h; i++){
		for(int j = 0; j < w; j++){
			ans += (!mp[i][j]);
		}
	}
	std::cout << ans << '\n';
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