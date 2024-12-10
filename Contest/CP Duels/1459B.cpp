#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
/*
0 2 4  6  8 10
1 4 9 16 25 36
1  3  5  7  9
4 12 24 40 60
0 1 2  3 4  5  6  7  8  9 10
1 4 4 12 9 24 16 40 25 60 36
*/
int db(int n){
	std::queue<std::array<int, 4>> q;
	q.push({0, 0, 0, n});
	q.push({0, 0, 1, n});
	q.push({0, 0, 2, n});
	q.push({0, 0, 3, n});
	std::set<std::pair<int, int>> s;
	while(q.size()){
		auto [x, y, dir, k] = q.front();
		q.pop();
		if(k == 0){
			s.insert({x, y});
			continue;
		}
		for(auto i : {-1, 1}){
			int ddir = dir + i;
			ddir = (ddir + 4) % 4;
			int dx = x + d[ddir][0], dy = y + d[ddir][1];
			q.push({dx, dy, ddir, k - 1});
		}
	}
	for(auto [x, y] : s){
		std::cout << "(" << x << ',' << y << ")\n";
	}
	return (int)s.size();
}
i64 dp[2000];
void solve() {
	int n;
	std::cin >> n;
	// if(n % 2 == 0) n --;
	// std::cout << (n) * 4 << "\n";
	std::cout << dp[n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));
    dp[0] = 1;
    for(i64 i = 1, odd = 1,sum = 0, even = 0; i <= 1000; i++){
    	if(i & 1){
    		even += 2;
    		sum += even;
    		dp[i] = sum * 2;
    	} else {
    		odd++;
    		dp[i] = odd * odd;
    	}
    }
    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}