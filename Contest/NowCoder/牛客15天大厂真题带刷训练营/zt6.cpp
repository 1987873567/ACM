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
	std::string s;
	std::cin >> s;
	std::vector<int> v(26);
	for(auto i : s){
		v[i - 'a']++;
	}
	using pci = std::pair<int, char>;
	std::priority_queue<pci, std::vector<pci>, std::greater<>> q;
	for(int i = 0; i < 26; i++){
		if(v[i]){
			q.push({0, char(i + 'a')});
		}
	}
	std::string ans = "";
	while(ans.size() != s.size()){
		auto [d, c] = q.top();
		q.pop();
		if(c == s[ans.size()]){
			if(q.empty()){
				return std::cout << "-1\n", void();
			}
			auto t = q.top();
			ans += t.second;
			t.first += 1;
			q.pop();
			q.push(t);
			q.push({d, c});
		} else {
			ans += c;
			q.push({d + 1, c});
		}
	}
	std::cout << ans << "\n";
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