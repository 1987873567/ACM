#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
std::map<char,int> id{{'(', -1},{')', -2},{'^', -3}, {'*', -4}, {'+', -5}};
void solve() {
	std::string s;
	std::cin >> s;
	std::list<i64> l;
	int n = s.size();
	for(int i = 0; i < n;){
		if(s[i] >= '0' && s[i] <= '9'){
			i64 x = 0;
			while(s[i] >= '0' && s[i] <= '9'){
				x = x * 10 + s[i] - '0';
				i++;
			}
			l.push_back(x);
		} else {
			l.push_back(id[s[i++]]);
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