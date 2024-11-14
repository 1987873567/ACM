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
	int n, m, k;
	std::cin >> n >> m >> k;
	std::priority_queue<i64> R;
	std::priority_queue<i64, std::vector<i64>, std::greater<>> L;
	auto add = [&](i64 x){
		if(!R.size() || R.top() >= x ) R.push(x);
		else L.push(x);
		if(R.size() > L.size() + 1){
			L.push(R.top());
			R.pop();
		} else if(R.size() + 1 < L.size()) {
			R.push(L.top());
			L.pop();
		}
	};
	auto ask = [&](int flag){
		if(flag){
			if(L.size() > R.size()){
				return L.top();
			} else {
				return R.top();
			}
		} else {
			return i64((L.top() + R.top()) / 2);
		}
	};
	for(i64 i = 0, x; i < n; i++){
		std::cin >> x;
		add(x);
	}
	int N = n;
	for(i64 i = 0; i < m; i++, N++){
		i64 mid = ask(N & 1) + k;
		add(mid);
	}
	std::vector<i64> ans;
	while(L.size()){
		ans.push_back(L.top());
		L.pop();
	}
	while(R.size()){
		ans.push_back(R.top());
		R.pop();
	}
	std::sort(all(ans));
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
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