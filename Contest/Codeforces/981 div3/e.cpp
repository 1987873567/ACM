#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void db(){
    int n = 4;
    std::vector<int> v(n);
    std::iota(all(v), 0);
    auto print = [&](){
        for(int i = 0; i < n; i++){
            std::cerr << v[i] << " \n"[i == n - 1];
        }
    };
    do{
        int flag = 1;
        for(int i = 0; i < n; i++){
            if(!(v[i] == i || v[v[i]] == i)){
                flag = 0;
                break;
            }
        }
        if(flag)print();
    }while(std::next_permutation(all(v)));
}

void solve() {
	// db();
    int n;
    std::cin >> n;
    std::vector<int> v(n + 1), id(n + 1), vis(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
        id[v[i]] = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	if(!(v[i] == i || v[v[i]] == i)){\
    		int a = v[i], b = id[i];
    		std::swap(v[a], v[b]);
    		id[v[a]] = a;
    		id[v[b]] = b;
    		ans++;
    	}
    }
    std::cout << ans << '\n';
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