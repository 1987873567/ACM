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
    // std::vector g(n, std::vector<int>());
    std::vector<int> r(n), g(n);
    for(int i = 0, x; i < n; i++){
        std::cin >> x;
        x--;
        g[i] = x;
        // std::cerr << i << " " << x << "\n";
        r[x]++;
    }
    std::queue<int> q;
    std::vector<int> ans, vis(n);
    for(int i = 0; i < n; i++){
        if(!r[i]) q.push(i);
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        vis[x] = 1;
        int flag = 0;
        if(s[x] == '1')s[x] = ((s[x] - '0') ^ 1) + '0',ans.push_back(x + 1), flag = 1;
        int y = g[x];
    	if(flag) s[y] = ((s[y] - '0') ^ 1) + '0';
        if(--r[y] == 0){
            q.push(y);
        }
    }

    for(int i = 0; i < n; i++){
    	if(!vis[i]){
    		int cnt = 0, c1 = 0;
    		for(int x = i, flag = 0; !vis[x]; x = g[x]){
    			vis[x] = 1;
    			if(s[x] == '1')c1++;
    			cnt++;
    		}
    		if(c1 & 1){
    			std::cout << "-1\n";
    			return;
    		}
    		std::vector<int> a1, a2;
    		for(int x = i, c = 0, flag = 0; c < cnt; x = g[x], c++){
    			if(!c || (flag ^ s[x]) & 1){
    				flag = 1;
    				a1.push_back(x + 1);
    			} else {
    				flag = 0;
    			}
    		}
    		for(int x = i, c = 0, flag = 0; c < cnt; x = g[x], c++){
    			if(c && (flag ^ s[x]) & 1){
    				flag = 1;
    				a2.push_back(x + 1);
    			} else {
    				flag = 0;
    			}
    		}
    		if(a1.size() < a2.size()){
    			ans.insert(ans.end(), all(a1));
    		} else {
    			ans.insert(ans.end(), all(a2));
    		}
    	}
    }

    std::cout << ans.size() << "\n";
    for(auto i : ans){
        std::cout << i << " ";
    }
    std::cout << "\n";
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