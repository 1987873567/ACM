#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

void solve() {
	std::string s, l;
	std::cin >> s >> l;
	int flag = 1;
	flag &= (s == "steam");
	flag &= (l.size() <= 4 && l.find_first_not_of("0123456789") == l.npos);
	if (!flag) return NO,void();
	flag &= (l[0] != '0');
	int n = std::stoi(l.c_str());
	flag &= (n >= 1 && n <= 5000);
	if(flag) YES;
	else NO;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}