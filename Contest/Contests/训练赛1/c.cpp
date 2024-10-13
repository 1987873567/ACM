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
	std::vector<int> v(n);

	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}

    auto fun = [&](int x) -> bool{
        std::unordered_map<int, int> mp;
        for(int i = x; i < n; i++){
            mp[v[i]]++; 
        }
        if(mp.size() == n - x)return 1;
        for(int i = x; i < n; i++){
            mp[v[i]]--;
            if(!mp[v[i]])mp.erase(v[i]);
            mp[v[i - x]]++;
            if(mp.size() == n - x){
                return 1;
            }
            
        }
        return 0;
    };
	int l = 0, r = n + 1;
    while(l + 1 != r){
        int mid = (l + r) >> 1;
        if(fun(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    for(int i : {l, r}){
        if(fun(i)){
            std::cout << i << "\n";
            return;
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