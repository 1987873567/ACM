#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct BT{
	int n;
	std::vector<int> t;
	BT(int n):n(n){
		t.assign(n + 1, 0);
	}
	void add(int i, int val){
		for(;i <= n; i += (i & (-i))) t[i] += val;
	}
	int ask(int i){
		int res = 0;
		for(;i; i -= (i & (-i))) res += t[i]; 
		return res;
	}
	int ask(int l, int r){
		return ask(r) - ask(l - 1);
	}
};

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	BT N(n + 1), C(n + 1);
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'N') N.add(i, 1);
		if(s[i - 1] == 'C') C.add(i, 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'A'){
			ans += N.ask(i) * C.ask(i, n);
		}
	}
	if(ans > k){
		std::cout << "-1\n";
		return;
	}
	char op[4] = {'S', 'N', 'A', 'C'};
	int flag = 0;
	auto dfs = [&](auto &&self, int x, int res){
		if(x == n + 1 ){
			if(res == k) flag = 1;
			return;
		}
		if(flag)return;
		if(s[x - 1] == '?'){
			for(int j = 0; j < 4; j++){
				s[x - 1] = op[j];
				if(j == 1) N.add(x, 1);
				if(j == 3) C.add(x, 1);
				self(self, x + 1, res + (j == 2 ? N.ask(x) * C.ask(x, n) : 0));
				if(flag) return;
				s[x - 1] = '?';
				if(j == 1) N.add(x, -1);
				if(j == 3) C.add(x, -1);
			}
		} else {
			self(self, x + 1, res);
		}
	};
	dfs(dfs, 1, ans);
	if(flag){
		std::cout << s << "\n";
	} else {
		std::cout << "-1\n" << "\n";
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