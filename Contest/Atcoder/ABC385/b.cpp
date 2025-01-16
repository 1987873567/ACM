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
	int h, w, x, y;
	std::cin >> h >> w >> x >> y;
	x--, y--;
	std::vector<std::string> mp(h);
	for(int i = 0; i < h; i++){
		std::cin >> mp[i];
	}
	std::string s;
	std::cin >> s;
	std::set<std::pair<int, int>> ans;
	for(auto &op : s) {
		if(op == 'U'){
			if(mp[x - 1][y] != '#'){
				x -= 1;
				if(mp[x][y] == '@'){
					ans.insert({x, y});
				}
			}
		} else if (op == 'D'){
			if(mp[x + 1][y] != '#'){
				x += 1;
				if(mp[x][y] == '@'){
					ans.insert({x, y});
				}
			}
		} else if (op == 'L'){
			if(mp[x][y - 1] != '#'){
				y -= 1;
				if(mp[x][y] == '@'){
					ans.insert({x, y});
				}
			}
		} else if (op == 'R'){
			if(mp[x][y + 1] != '#'){
				y += 1;
				if(mp[x][y] == '@'){
					ans.insert({x, y});
				}
			}
		}
	}
	std::cout << x + 1 << " " << y + 1 << " " << ans.size() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}