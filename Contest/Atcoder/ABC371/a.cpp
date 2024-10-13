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
	std::string  s;
	std::cin >> s;
	std::vector<std::vector<int>> g(4);
	std::vector<int> r(3);
	
	if (s == "<") {
		g[0].push_back(1);
		r[1]++;
	} else {
		g[1].push_back(0);
		r[0]++;
	}

	std::cin >> s;
	if (s == "<") {
		g[0].push_back(2);
		r[2]++;
	} else {
		g[2].push_back(0);
		r[0]++;
	}

	std::cin >> s;
	if (s == "<") {
		g[1].push_back(2);
		r[2]++;
	} else {
		g[2].push_back(1);
		r[1]++;
	}

	std::queue<int> q;
	for(int i = 0; i < 3; i++){
		if(!r[i])q.push(i);
		// std::cout << r[i] << " \n"[i == 2];
	}
	std::string ans = "";
	while(q.size()){
		int t = q.front();
		q.pop();
		// std::cout << char('A' + t) << "\n";
		ans += ('A' + t);
		for(auto i : g[t]){
			if(--r[i] == 0) {
				q.push(i);
			}
		}
	}
	assert(ans.size() == 3);
	std::cout << ans[1] << "\n";
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