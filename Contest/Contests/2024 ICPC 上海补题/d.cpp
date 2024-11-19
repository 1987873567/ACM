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
	std::string s;
	std::cin >> s;
	int pos = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			pos = i;
			break;
		}
	}
	if(s[n - 1] == '0' && s[n - 2] == '0'){
		YES;
		return;
	}
	if(n - pos <= 3){
		NO;
		return;
	}
	int c1 = 0, c0 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			c1++;
		}else{
			c0++;
		}
		if(c1 && c1 - c0 >= 0) pos = i;
		else {
			c1 = 0;
			c0 = 0;
			if(n - i <= 4){
				return NO, void();
			}
		}
	}
	if(pos < n - 2 || !c0) return NO,void();
	YES;
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
/*
*/