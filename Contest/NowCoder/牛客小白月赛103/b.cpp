#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool check(char c){
	return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c <= '9' && c >= '0');
}
void solve() {
	std::string s;
	std::cin >> s;
	int p = s.find('@');
	if(p == s.npos) return NO, void();
	std::string local = s.substr(0, p), domian = s.substr(p + 1);
	if(!local.size() || !domian.size()) return NO,void();
	if(local.size() > 64 || domian.size() > 255) return NO,void();
	if(!check(local[0]) || !check(domian[0]) || !check(local.back()) || !check(domian.back())) return NO,void();
	for(auto i : local){
		if(check(i) || i == '.'){

		}else{
			return NO,void();
		}
	}
	for(auto i : domian){
		if(check(i) || i == '.' || i == '-'){

		}else{
			return NO,void();
		}
	}
	YES;
	// std::cout << local << " " << domian << "\n";
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