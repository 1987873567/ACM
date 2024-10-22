#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[8][2] = {{0, 1},{1,1},{1, 0},{1,-1}, {0, -1},{-1,-1}, {-1, 0},{-1,1}};
int vis[30][30];
int sx, sy, ex, ey, n;
struct node{
	int x = -1, y = -1;
};
node pre[20][20];
void solve() {
	std::cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> vis[i][j];
		}
	}
	std::cin >> sx >> sy;
	std::cin >> ex >> ey;
	std::queue<node> q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	while(q.size()){
		auto [x, y] = q.front();
		q.pop();
		if(x == ex && y == ey){
			node temp = {x, y};
			while(pre[temp.x][temp.y].x != -1 && pre[temp.x][temp.y].y != -1){
				std::cout << temp.x << " " << temp.y << ";";
				temp = pre[temp.x][temp.y];
			}
			std::cout << sx << " " << sy << ";";
			return;
		}
		for(int i = 0; i < 8; i++){
			int dx = x + d[i][0], dy = y + d[i][1];
			if(dx >= 0 && dx < n && dy >= 0 && dy < n && !vis[dx][dy]){
				vis[dx][dy] = 1;
				pre[dx][dy] = {x, y};
				q.push({dx, dy});
			}
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