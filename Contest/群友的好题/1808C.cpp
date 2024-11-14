#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
i64 dp[20][1030];
std::string num;
int f(int x){
	int max = 0, min = 10;
	for(int i = 0; i < 10; i++){
		if(x >> i & 1){
			max = i;
			min = std::min(min, i);
		}
	}
	return max - min;
}
int gold;
i64 Ans = 0;
i64 f(int len, int mask, int is_limit, int is_num, i64 Num){
	if(len == num.size()){
		if(f(mask) == gold){
			Ans = std::max(Ans, Num);
		}
		return Num;
	}
	i64 res = 0;
	if(!is_limit && dp[len][mask] >= 0) {
		// std::cerr << len << ' ' << dp[len][mask] << ' ' << Num << "\n";
		res = std::max(res, f(len + 1, mask, is_limit, is_num, dp[len][mask]));
	}
	if(!is_num) res = std::max(res, f(len + 1, mask, 0, is_num, Num * 10));

	for(int d = 1 - is_num, up = (is_limit ? (num[len] - '0') : 9); d <= up; d++){
		res = std::max(res, f(len + 1, mask | (1 << d), is_limit && d == up, 1, Num * 10 + d));
	}
	if(!is_limit && is_num) dp[len][mask] = std::max(res, dp[len][mask]);
	return res;
}
void cal(){
	Ans = 0;
	memset(dp, -1, sizeof dp);
	f(0, 0, 1, 0, 0);
}

void solve() {
	i64 l, r;
	std::cin >> l >> r;
	num = std::to_string(r);
	for(int i = 0; i <= 9; i++){
		gold = i;
		cal();
		if(Ans >= l){
			std::cout << Ans << "\n";
			return;
		}
	}
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