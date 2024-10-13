#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;

int tire[N * 2 + 10][26], cnt[N + 10], tot = 0;

void insert(std::string &s){
	int p = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		int c = s[i] - 'a';
		if(!tire[p][c]){
			tire[p][c] = ++tot;
		}
		p = tire[p][c];
		cnt[p]++;
	}
}

i64 ask(std::string &s){
	i64 p = 0, res = 0;
	for(auto i : s){
		int c = i - 'a';
		if(!tire[p][c])break;
		p = tire[p][c];
		res += cnt[p];
	}
	return res;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::string> v(n);
	i64 ans = 0;
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
		ans += v[i].size();
		insert(v[i]);
	}
	ans = ans * 2 * n;

	for (int i = 0; i < n; i++){
		ans -= 2 * ask(v[i]);
	}
	std::cout << ans << "\n";
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