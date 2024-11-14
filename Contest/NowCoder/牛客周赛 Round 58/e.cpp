#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

inline long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

inline long long binomial_coefficient(long long n, long long k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long num = 1, denom = 1;
    for (long long i = 0; i < k; ++i) {
        num = (num * (n - i)) % MOD;
        denom = (denom * (i + 1)) % MOD;
    }
    return (num * mod_pow(denom, MOD - 2, MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, m;
        cin >> n >> m;

        if (m > n + 1) {
            cout << 0 << endl;
            continue;
        }

        long long total_combinations = mod_pow(2, n + 1, MOD) - 1;
        long long exclude_combinations = 0;

        for (long long i = 0; i < m; ++i) {
            exclude_combinations = (exclude_combinations + binomial_coefficient(n + 1, i)) % MOD;
        }

        long long result = (total_combinations - exclude_combinations + MOD) % MOD;
        cout << result << endl;
    }

    return 0;
}
