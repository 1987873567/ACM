#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void db(int n, int m){
	std::vector<int> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			i64 t = i * i + j * j;
			i64 ans = 0;
			// if(t % 6 == 0) 
				ans = t % m;
			// q.push_back(i * i + j * j);
			std::cout << std::fixed << std::setw(3) << ans << " \n"[j == n];
		}
	}
	// std::sort(all(q));
	// for(auto i : q){
	// 	std::cout << i << ' ';
	// }
	// std::cout << "\n";
}

void solve() {
	// db(6, 5);
	int n, m;
	std::cin >> n >> m;
	i64 N = std::min(n, m);
	i64 a = n / m, b = n % m, s = 0;
	std::vector<i64> r(N + 1);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			i64 t = i * i + j * j;
			if(t % m == 0) {
				r[i]++;
				if(i <= b && j <= b) s += 1;
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		r[i] += r[i - 1];
	}
	
	i64 ans = a * a * r[N];
	ans += r[b] * a;
	ans += r[b] * a;
	ans += s;
	std::cout << ans << "\n";
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