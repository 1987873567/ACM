#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(a) a.begin(), a.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int mod = 1e9 + 7;
void solve() {
    std::string s;
    std::vector<std::string> c;
    while (std::cin >> s && s != "FIN") {
    	c.push_back(s);
    }
    std::stack<i64> st;
    st.push(0);
    i64 ans = 0, cnt = 0;
    for (int i = 0; i < (int)c.size(); i++) {
    	if(c[i] == "LIBRARY"){
    		st.top()++;
    	} else if (c[i] == "REP") {
    		st.push(0);
    	} else if (c[i] == "FOR") {
    		int t = std::stoi(c[i + 1].c_str());
            int p = st.top();st.pop();
            st.top() += p * t;
            st.top() %= mod;
    	}
    }
    std::cout << st.top() << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%d",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}