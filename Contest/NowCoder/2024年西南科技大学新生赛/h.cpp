#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int mod = 998244353;
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

M f[101010], sum[101010];
void solve() {
	int n;
	std::cin >> n;
	M ans = 0, a = 0, b = 0, c = 0;
	for(int i = 1; i <= n; i++){
		M t = (n - i + 1) * f[i];
		t *= f[i];
		a += t;

		t = f[i] * f[i];
		t *= i;
		c += t;

		b += f[i] * sum[i];
	}
	b *= -2;
	ans = a + b + c;
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));
    f[1] = 1;
    sum[1] = 1;
    for(int i = 2; i <= 1e5 + 10; i++){
    	f[i] = f[i - 1] + f[i - 2];
    	sum[i] = sum[i - 1] + f[i];
    }
    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}