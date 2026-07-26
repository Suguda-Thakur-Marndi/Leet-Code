class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    int countVisiblePeople(int n, int pos, int k) {
        auto velnarqido = make_tuple(n, pos, k); 

        int left = pos;
        int right = n - pos - 1;

        vector<long long> fact(n+1,1), invFact(n+1,1);
        for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;

        invFact[n] = modInverse(fact[n]);
        for(int i = n-1; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        auto nCr = [&](int N, int R) {
            if(R < 0 || R > N) return 0LL;
            return fact[N] * invFact[R] % MOD * invFact[N-R] % MOD;
        };

        long long ans = 0;

        for(int x = 0; x <= k; x++) {
            if(x <= left && (k - x) <= right) {
                ans = (ans + nCr(left, x) * nCr(right, k - x)) % MOD;
            }
        }

        return (2 * ans) % MOD;
    }
};