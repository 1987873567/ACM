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
	std::stack<char> st;
	for(int i = 0; i < n; i++){
		if (s[i] == 'c') {
			if(st.size()){
				if(st.top() == 'f'){
					st.pop();
				} else {
					st.push(s[i]);
				}
			}else{
				st.push(s[i]);
			}
		} else if(s[i] == 'b'){
			if(st.size()){
				if(st.top() == 't'){
					st.pop();
				} else {
					st.push(s[i]);
				}
			}else{
				st.push(s[i]);
			}
		} else {
			st.push(s[i]);
		}
	}
	std::cout << st.size() << "\n";
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