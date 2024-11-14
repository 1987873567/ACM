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
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	std::vector<int> v(26);
	for(auto i : s){
		v[i - 'a']++;
	}
	int p = 0;
	char c;
	for(int i = 0; i < 26; i++){
		if(k > v[i]){
			k -= v[i];
		} else {
			c = i + 'a';
			p = k;
			break;
		}
	}

	std::vector<int> next(n);
	for(int i = n - 1; i >= 0; i--){
		if (i < n - 1 && s[i] == s[i + 1]) {
			next[i] = next[i + 1];
		} else {
			next[i] = i + 1;
		}
	}

	std::deque<int> q;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] != c)continue;
		int x = next[i];
		if(x < n && s[i] < s[x]){
			q.emplace_back(i);
		} else {
			q.emplace_front(i);
		}
	}
	k = p;
	while(k--){
		p = q.front();
		q.pop_front();
	}
	std::string ans;
	ans += c;
	ans += s.substr(0, p);
	ans += s.substr(p + 1);
	std::cout << ans << "\n";
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