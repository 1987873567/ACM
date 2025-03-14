#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool check(char x){
	return x == 'a' || x == 'o' || x == 'e' || x == 'i' || x == 'u';
}

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> vis(n);
    for(int i = 0; i < n; i++){
    	char x = s[i];
    	if(!check(x)){
    		std::set<char> se;
    		int l = i, r = i;
    		while(r < n && !check(x)){
    			se.insert(x);
    			x = s[r++];
    		}
    		if(se.size() == 1 && r - l + 1 > 3){

    		} else {
    			
    		}
    	}
    }
}

signed main() {
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