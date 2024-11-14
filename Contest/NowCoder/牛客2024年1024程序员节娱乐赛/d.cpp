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
unsigned char cipher[] = {
        198, 44, 113, 215, 43, 231, 181, 44, 147, 95, 61, 181, 79, 180, 95, 79, 180, 232, 181, 79, 46,
        95, 231, 147, 95, 164, 181, 146, 79, 65, 63, 82, 116, 77, 0
    };
    
    int length = sizeof(cipher) / sizeof(cipher[0]);
    unsigned char decrypted_flag[35]; // 存储解密后的 flag

    for (int i = 0; i < length; i++) {
        decrypted_flag[i] = cipher[i] / 17; // 逆向解密
        std::cout << decrypted_flag[i]; // 输出解密后的字符
    }
    
    std::cout << "\n";
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