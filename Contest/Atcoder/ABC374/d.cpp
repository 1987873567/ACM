#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct point{
	int x, y;
};

bool check(point p1, point p2, point q){
	bool ans = ((q.x - p1.x) * (p2.y - p1.y) == (p2.x - p1.x) * (q.y - p1.y));
	ans &= (std::min(p1.x , p2.x) <= q.x && q.x <= std::max(p1.x , p2.x));
	ans &= (std::min(p1.y , p2.y) <= q.y && q.y <= std::max(p1.y , p2.y));
	return ans;
}

void solve() {
	int n, t, s;
	std::cin >> n >> t >> s;
	std::vector<std::array<int, 4>> seg;
	for(int i =0; i < n; i++){
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		seg.push_back({a, b, c, d});
	}
	int flag = 1;
	while(flag){
		for(int i = 0; i < n; i++){
			point a = {seg[i][0], seg[i][1]};
			point b = {seg[i][2], seg[i][3]};
			for(int j = 0; j < n; j++){
				point c = {seg[j][0], seg[j][1]};
				point d = {seg[j][2], seg[j][3]};
				if(check(a, b, c) && check(a, b, d)){
					
				}
			}
		}
	}

	ld ans = 1e9;
	std::vector<int> id(n);
	std::iota(all(id), 0);
	do{
		point temp = {0, 0};
		ld res = 0;
		for(int i = 0; i < n; i++){

		}

	}while(std::next_permutation(all(id)));


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