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
	std::unordered_map<int,std::queue<int>> pos;
	std::unordered_map<int, int> homo;
	int f1 = 0, f2 = 0;
	while(n--){
		std::string op;
		int x;
		std::cin >> op >> x;
		if(op[0] == 'i'){
			pos[x].push(x);
			if(pos.size() > 1) f2 = 1;
			if(pos[x].size() > 1){
				homo[x]++;
				f1 = 1;
			}
		}else{
			if(pos.count(x) && pos[x].size()){
				auto t = pos[x].front();
				homo[x]--;
				if(homo.count(x) && homo[x] < 1) homo.erase(x), f1 = (homo.size() > 0);
				pos[x].pop();
				if(!pos[x].size())pos.erase(x), f2 = (pos.size() > 1);
			}
		}
		if(f1 && f2){
			std::cout << "both\n";
		} else if(f1){
			std::cout << "homo\n";
		} else if(f2){
			std::cout << "hetero\n";
		} else {
			std::cout << "neither\n";
		}
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