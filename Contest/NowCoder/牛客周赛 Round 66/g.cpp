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
int mex(int x){
    for(int i = 0; i < 10; i++){
        if(!(x >> i & 1))return i;
    }
    return 10;
}

std::string S;
int n, M;
int f(int len, int mask, int is_limit, int is_num) {
	if(len == n) {
        return mex(mask) == M;
	}

    if(!is_limit && dp[len][mask] >= 0) return dp[len][mask];
    int res = 0;
    if(!is_num) res = f(len + 1, mask, 0, is_num);

    for (int i = 1 - is_num, up = is_limit ? (S[len] - '0') : 9; i <= up; i++) {
        res += f(len + 1, mask | (1 << i), is_limit && i == up, 1);
    }

    if(!is_limit && is_num) dp[len][mask] = res;
    return res;
}

i64 cal(i64 x){
    memset(dp, -1, sizeof dp);
    S = std::to_string(x);
    n = S.size();
    return f(0, 0, 1, 0);
}

i64 cal(i64 x, i64 y){
    return cal(y) - cal(x - 1);
}

void solve() {
	i64 x, k;
	std::cin >> x >> k;
    for(int i = 10; i >= 0; i--){
        M = i;
        int res = cal(x, x + k);
        if(res > 0){
            std::cout << i << ' ' << res << "\n";
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