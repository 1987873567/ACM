#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
struct node{
	int l, r, id;
};
void solve() {
	int n, qx;
	std::cin >> n >> qx;
	std::string s;
	std::cin >> s;
	std::vector<int> R(n + 1), E(n + 1), D(n + 1), ans(qx);
	for(int i = 1; i <= n; i++){
		R[i] = R[i - 1] + (s[i - 1] == 'r');
		E[i] = E[i - 1] + (s[i - 1] == 'e');
		D[i] = D[i - 1] + (s[i - 1] == 'd');
	}
	std::vector<node> q(qx); 
	for(int i = 0; i < qx; i++){
		std::cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	std::sort(all(q), [&](node x, node y){
		if(x.l == y.l) return x.r < y.r;
		return x.l < y.l;
	});
	int l = 1, r = 1, ANS = 0;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'e') ANS += (R[i]) * (D[n] - D[i]);
	}
	auto add = [&](int x){
		if(s[x - 1] == 'r'){
			ANS += (E[r] - E[l - 1]) * (D[n] - D[r]);
		}else if(s[x - 1] == 'e'){
			ANS -= (R[x]) * (D[n] - D[x]);
			ANS += (D[n]  - D[l]) * (R[l - 1]);
		}else{
			ANS -= (E[r] - E[l - 1]) * (R[l - 1]);
		}
	};
	auto del = [&](int x){
		if(s[x - 1] == 'r'){
			ANS -= (E[r] - E[l - 1]) * (D[n] - D[r]);
		}else if(s[x - 1] == 'e'){
			ANS -= (D[n]  - D[l]) * (R[l - 1]);
			ANS += (R[x]) * (D[n] - D[x]);
		}else{
			ANS += (E[r] - E[l - 1]) * (R[l - 1]);
		}
	};
	for(int i = 0; i < qx; i++){
		while(r < q[i].r){
			r++;
			add(r);
		}
		while(l > q[i].l){
			l--;
			add(l);
		}
		while(r > q[i].r){
			del(r);
			r--;
		}
		while(l < q[i].l){
			del(l);
			l++;
		}
		ans[q[i].id] = ANS;
	}
	for(int i = 0; i < qx; i++){
		std::cout << ans[i] << "\n";
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