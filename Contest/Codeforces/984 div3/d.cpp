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
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> mp(n);
	for(int i = 0; i < n; i++){
		std::cin >> mp[i];
	}

	int layer = std::min(n, m) / 2;
	std::vector<std::string> p;
	std::vector<std::vector<int>> vis(n, std::vector<int>(m));
	for(int i = 0; i < layer; i++){
		std::string temp = "";
		int x = i, y = i;
		while(y < m && !vis[x][y]){
			temp += mp[x][y];
			vis[x][y] = 1;
			y++;
		}
		y--;
		x++;
		while(x < n && !vis[x][y]){
			temp += mp[x][y];
			vis[x][y] = 1;
			x++;
		}
		x--;
		y--;
		while(y >= 0 && !vis[x][y]){
			temp += mp[x][y];
			vis[x][y] = 1;
			y--;
		}
		y++;
		x--;
		while(x >= 0 && !vis[x][y]){
			temp += mp[x][y];
			vis[x][y] = 1;
			x--;
		}
		p.push_back(temp);
	}
	int ans = 0;
	for(auto &ss : p){
		int Res = 0;
		int nn = ss.size();
		ss += ss;
		for(int i = 0; i < 4; i++){
			int res = 0;
			for(int j = i; j < i + nn; j++){
				if(ss.substr(j, 4) == "1543")res++;
			}
			Res = std::max(res, Res);
		}
		ans += Res;
	}
	std::cout << ans << "\n";
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