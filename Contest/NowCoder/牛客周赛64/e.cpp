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
	int n = s.size();
	std::vector<int> v(26);
	int max = 0;
	std::priority_queue<std::array<int, 2>> q;
	for(auto i : s){
		v[i - 'a'] ++;
		max = std::max(v[i - 'a'], max);
	}
	for(int i = 0; i < 26; i++){
		if(v[i])q.push({v[i], i});
	}
	if(max > (n) / 2){
		std::cout << "-1\n";
	}else{
		std::queue<std::array<int, 2>> qq;
		std::string ans = "";
		for(int i = 0; i < n; i++){
			while(q.size() && q.top()[1] == s[i] - 'a'){
				qq.push(q.top());
				q.pop();
			}
			if(!q.size())break;
			auto t = q.top();
			q.pop();
			t[0]--;
			// std::cout << char(t[1] + 'a');
			ans += (t[1] + 'a');
			if(t[0]) q.push(t);
			while(qq.size()){
				q.push(qq.front());
				qq.pop();
			}
		}
		// if(qq.size()){
		// 	std::cout << "yes:" << char(qq.front()[1] + 'a') << "\n";
		// }
		if(qq.size()){
			auto t = qq.front();
			for(int i = 0; i < n- 1; i++){
				if(ans[i] - 'a' != t[1] && s[i] - 'a' != t[1]){
					ans += ans[i];
					ans[i] = t[1] + 'a';
					break;
				}
			}
		}
		std::cout << ans << "\n";
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