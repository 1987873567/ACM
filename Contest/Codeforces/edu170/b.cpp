#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int mod = 1e9 + 7;
template<long long m>
class modint {
    using ll = long long;
    using uint = unsigned int; 
    using mint = modint;     

public:
    modint() : _v(0) {};
    modint(long long v) {
        ll x = (ll) (v % (ll) (umod()));
        if (x < 0)x += umod();
        _v = (uint) (x);
    }

    uint val() const { return _v; }
    mint &operator=(const mint &rhs){
      _v = rhs._v;
      return *this;
    }
    mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        if (_v >= umod())_v -= umod();
        return *this;
    }

    mint &operator-=(const mint &rhs) {
        _v -= rhs._v;
        if (_v >= umod())_v += umod();
        return *this;
    }

    mint &operator*=(const mint &rhs) {
        unsigned long long x = _v;
        x *= rhs._v;
        _v = (uint) (x % umod());
        return *this;
    }

    mint &operator/=(const mint &rhs) {
        return *this = *this * rhs.inv();
    }

    mint &operator+() { return *this; }
    mint &operator-() { return mint() - *this; }

    mint pow(ll n) const {
        mint ans = 1, base = *this;
        while (n) {
            if (n & 1)ans *= base;
            base *= base;
            n >>= 1;
        }
        return ans;
    }

    mint inv() const {// 求逆元函数
        assert(_v != 0);
        return pow(umod() - 2);
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {  // 加法运算符重载
        return mint(lhs) += rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {  // 乘法运算符重载
        return mint(lhs) *= rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {  // 减法运算符重载
        return mint(lhs) -= rhs;
    }

    friend mint operator/(const mint &lhs, const mint &rhs) {  // 除法运算符重载
        return mint(lhs) /= rhs;
    }

    friend std::istream &operator>>(std::istream &is, mint &rhs) {//重载输入
        long long x;
        is >> x;
        rhs = modint(x);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, mint &rhs) {//重载输出
        return os << rhs._v;
    }

private:
    uint _v;                             // 存储模运算的结果
    static uint umod() { return m; }         // 返回模数 m
};
using M = modint<mod>;// 别名定义，使用 modint<mod> 定义 mint 类
M qpow(M x,int y){
  M res = 1;
  for(;y;y>>=1,x*=x){
    if(y&1)res*=x;
  }
  return res;
}
//组合数
class Comb{
public:
    Comb():n{0},Fac{1},Inv{1}{}
    Comb(long long x):Comb(){
        init(x);
    }
    void init(long long x){//初始化
        Fac.resize(x+10);
        Inv.resize(x+10);
        Fac[0]=1;
        for(long long i = 1;i<=x; ++i){
            Fac[i]=M(Fac[i-1]*M(i));
        }
        Inv[x]=qpow(Fac[x],mod-2);
        for(long long i = x-1;i>=0;--i){
            Inv[i]=M(M(i+1)*Inv[i+1]);
        }
        n=x;
    }
    M qpow(M a,long long b){//快速幂
        M res = 1;
        for(;b;b>>=1,a*=a){
            if(b&1)res*=a;
        }
        return res;
    }
    M inv(int m){//阶乘的逆元
        if(n<m)init(2*m);
        return Inv[m];
    }
    M fac(int m){//阶乘
        if(n<m)init(2*m);
        return Fac[m];
    }
    M C(int b,int a){//组合数
        if(a>b)return M(0);
        return fac(b)*inv(b-a)*inv(a);
    }
private:
    std::vector<M> Fac,Inv;
    int n;
}C(1e5 + 1);
void solve() {
	int t;
	std::cin >> t;
	std::vector<int> n(t), k(t);
	for(int i = 0; i < t; i++)std::cin >> n[i];
	for(int i = 0; i < t; i++)std::cin >> k[i];
	for(int i = 0; i < t; i++){
		M ans = qpow(2, k[i]);
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