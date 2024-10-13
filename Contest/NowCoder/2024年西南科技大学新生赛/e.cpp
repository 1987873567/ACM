#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
std::vector<std::string> db;
int cal(std::string s){
	return std::stoi(s.substr(0, 2)) * 60 + std::stoi(s.substr(3, 2));
}
int cal(std::string x, std::string y){
	int m1, m2;
	if(y == "00:00" && x != "00:00"){
		m2 = 24 * 60;
	}else{
		m2 = cal(y);
	}
	m1 = cal(x);
	return m2 - m1;
}
	

void solve() {
	std::string x;
	std::cin >> x;
	auto p = std::lower_bound(all(db), x);
	if(p == db.end()){
		p = db.begin(); 
	}
	std::cout << *p << '\n';
	std::cout << cal(x, *p) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));
    auto fun = [&](std::string s){
    	for(int i = 0, j = s.size() - 1; i < j; i++ ,j--) {
    		if(s[i] != s[j]){
    			return 0;
    		}
    	}
    	return 1;
    };

    for(int i = 0; i < 24; i++){
    	for(int j = 0; j < 60; j++){
    		std::string temp = "", h, m;
    		if(i < 10) h = '0';
    		if(j < 10) m = '0';
    		h += std::to_string(i);
    		m += std::to_string(j);
    		temp += h;
    		temp += ":";
    		temp += m;
    		if(fun(temp)){
    			db.push_back(temp);
    		}
    	}
    }
    // for(auto i : db){
    // 	std::cout << i << "\n";
    // }
    /*
00:00
01:10
02:20
03:30
04:40
05:50
10:01
11:11
12:21
13:31
14:41
15:51
20:02
21:12
22:22
23:32
    */
    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}