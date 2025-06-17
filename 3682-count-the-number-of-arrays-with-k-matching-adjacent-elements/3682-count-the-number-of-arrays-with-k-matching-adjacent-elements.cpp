class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    // Modular exponentiation
    long long power(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y) {
            if (y & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    // Precompute factorials and their modular inverses
    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        init(n); // Precompute up to n
        long long res = m; // First element
        res = (res * nCr(n - 1, k)) % MOD;
        res = (res * power(m - 1, n - 1 - k)) % MOD;
        return res;
    }
};
