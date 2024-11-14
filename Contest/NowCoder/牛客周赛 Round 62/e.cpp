#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};


// template<class Info>
// struct Persistent_Segment_Tree{
// public:
// 	Persistent_Segment_Tree() : n(0) {}
//     Persistent_Segment_Tree(int n_, Info v_ = Info()) {
//         init(n_, v_);
//     }
//     template<class T> 
//     Persistent_Segment_Tree(std::vector<T> init_) {
//         init(init_);
//     }
//     void init(int n_, Info v_ = Info()) {
//         init(std::vector(n_, v_));
//     }
//     template<class T>
//     void init(std::vector<T> init_, int version = 0) {
//     	id = 0;
//         n = init_.size();
//         info.assign(n << 5, Info());
//         root.assign(n << 5, 0);
//         R.assign(n << 5, 0);
//         L.assign(n << 5, 0);
//         std::function<void(int, int, int)> build = [&](int p, int l, int r) {
//             if (r - l == 1) {
//                 info[p] = init_[l];
//                 return;
//             }
//             int m = (l + r) / 2;
//             L[version] = ++id;
//             R[version] = ++id;
//             build(L[version], l, m);
//             build(R[version], m, r);
//             pull(p, version);
//         };
//         build(1, 0, n);
//     }

//     void pull(int version) {
//     	info[version] = info[L[version]] + info[R[version]];
//     }

//     void modify(int l, int r, int last, int now, int pos, const Info &val){
//     	if(l == r){
//     		info[now] = info[last];
//     		return;
//     	}

//     	int m = (l + r) / 2;

//     	L[now] = L[last];
//     	R[now] = R[last];

//     	if(pos <= m){
//     		L[now] = ++id;
//     		modify(l, m, L[last], L[now], pos, val);
//     	} else {
//     		R[now] = ++id;
//     		modify(m + 1, r, R[last], R[now], pos, val);
//     	}
//     	pull(now);
//     }

//     void modify(int last, int now, int x, const Info &val){
//     	modify(1, n, root[last], root[now], x, val);
//     }

//     int rangQuery(int l, int r, int last, int now, int k){
//     	if(l == r) return l;
//     	int m = (l + r) / 2;
//     	int d = info[L[now]] - info[L[last]];

//     	if(d < k){

//     	}
//     }


// private:
// 	int n, id;
// 	std::vector<int> root, R, L;
// 	std::vector<Info> info;
// };

constexpr int N = 1e5;

int ID = 0, root[N << 5], R[N << 5], L[N << 5], val[N << 5];

void build(int version, int l, int r){
	if(l == r){
		val[l] = 0;
		return;
	}

	int m = (l + r) >> 1;
	L[version] = ++ID;
	R[version] = ++ID;

	build(version, l, m);
	build(version, m + 1, r);

	val[version] = val[L[version]] + val[R[version]];
}

void modify(int l, int r, int last, int now, int x, int v){
	if(l == r){
		val[now] = val[last] + v;
		return;
	}
	L[now] = L[last];
	R[now] = R[last];
	int m = (l + r) >> 1;
	if(x <= m){
		L[now] = ++ID;
		modify(l, m, L[last], L[now], x, v);
	} else {
		R[now] = ++ID;
		modify(m + 1, r, R[last], R[now], x, v);
	}
	val[now] = val[L[now]] + val[R[now]];
}

int query(int l, int r, int last, int now, int k){
	if(l == r) return l;

	int m = (l + r) >> 1;
	int d = val[L[now]] - val[L[last]];
	if (d < k) {
		return query(m + 1, r, R[last], R[now], k - d);
	} else {
		return query(l, m, L[last], L[now], k);
	}
}



void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n + 1), b(n);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		b[i - 1] = v[i];
	}
	std::sort(all(b));
	b.erase(std::unique(all(b)), b.end());

	int nn = b.size();
	root[0] = 1;
	build(root[0], 1, nn);
	for(int i = 0; i < n; i++){

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