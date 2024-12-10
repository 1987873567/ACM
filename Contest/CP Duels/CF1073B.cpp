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
	int n;
	std::cin >> n;
	std::queue<int> a;
	std::vector<int> vis(n + 1);
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		a.push(x);
	}
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		int cnt = 0;
		if(!vis[x]){
			while(a.size() && a.front() != x){
				vis[a.front()] = 1;
				cnt++;
				a.pop();
			}
		}
		if(a.size() && a.front() == x)vis[a.front()] = 1, cnt++, a.pop();
		std::cout << cnt << " \n"[i == n - 1];
	}

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