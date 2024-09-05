#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
std::vector<int> ans,now;
bool dfs (int d, i64 a, i64 b, i64 e) {
    if (d == 0) {
        if(a == 0 && (!ans.size() || now.back() < ans.back())){
            ans = now;
        }
        return a == 0;
    }
    i64 g = std::__gcd(a, b);
    a /= g;
    b /= g;
    bool sovled = 0;
    if(b > 1e7 * a) return false;
    //d/e >= a/b
    i64 e1 = std::max(e + 1, (b + a - 1) / a);
    for(;;e1++) {
        if(d * b < a * e1) return sovled;
        now.push_back(e1);
        sovled |= dfs(d - 1, a * e1 - b, b * e1, e1);
        now.pop_back();
    }
    return sovled;
}


void solve() {
	int a, b;
	std::cin >> a >> b;
    int flag = 0;
    for(int i = 1; i <= 100 && !flag; i++){
        flag |= dfs(i, a, b, 1);
    }
    if (flag) {
        for(auto i : ans){
            std::cout << i << " ";
        }
        std::cout << "\n";
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