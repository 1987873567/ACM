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
	std::vector<int> v(n), ans(n);
	ans[n - 1] = 0;
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	std::stack<int> st;
	for(int i = n - 1; i >= 0; i--){
		ans[i] += st.size();
		if(st.size()) ans[i] += (st.top() != i + 1);
		while(st.size() && v[st.top()] < v[i])	{
			st.pop();
		}
		st.push(i);
	}
	// // for(int i = 1; i <= n; i++){
	// 	while(st.size() && st.top() <= i)st.pop();
	// 	ans[i - 1] += st.size();
	// }
	for(auto i : ans){
		std::cout << i << " ";
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