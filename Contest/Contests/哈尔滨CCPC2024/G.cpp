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
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<int>> g(n + 1);
	std::set<int> K;

	for(int i = 0, x; i < k; i++){
		std::cin >> x;
		K.insert(x);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		std::cin >> a >> b;	
		g[a].push_back(b);
		g[b].push_back(a);
	}

	std::vector<bool> vis(n + 1);
	std::vector<std::vector<int>> op;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!K.count(i)){
			std::queue<int> q;
			q.push(i);
			vis[i] = 1;
			cnt++;
			while(q.size()){
				auto x = q.front();
				q.pop();
				std::vector<int> ans;
				ans.push_back(x);
				ans.push_back(0);
				for(auto i : g[x]){
					if(!vis[i]){
						vis[i] = 1;
						cnt++;
						ans.push_back(i);
						ans[1]++;
						if(!K.count(i)){
							q.push(i);
						}
					}
				}
				if(ans[1])op.push_back(ans);
			}
			break;
		}
	}

	if(cnt != n){
		NO;
	} else {
		YES;
		std::cout << op.size() << "\n";
		for(auto &i : op){
			for(auto &j : i){
				std::cout << j << " ";
			}
			std::cout << "\n";
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