#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORd(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define ms(x, n) memset(x, n, sizeof(x))
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define prec(x) fixed << setprecision((x))
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define long long long
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "------\n";
template<class T> inline int chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template<class T> inline int chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
const int INF = (int) 1e9;
const long LINF = (long) 1e18;

#define int long
const int maxn = 2000 + 15;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

struct Calculator {
    int MOD, a[maxn], f[maxn], g[maxn], finv[maxn], inv[maxn];
    int fpow(int n, int k) {
        int ret = 1;
        while (k) {
            if (k & 1) ret = (1LL * ret * n) % MOD;
            n = (1LL * n * n) % MOD;
            k >>= 1;
        }
        return ret;
    }
    int binom(int n, int k) {
        int ret = f[n];
        ret = (1LL * ret * finv[k]) % MOD;
        ret = (1LL * ret * finv[n - k]) % MOD;
        return ret;
    }
    int catalan(int n) {
        return (1LL * binom(2 * n, n) * inv[n + 1]) % MOD;
    }
    void initA() {
        a[1] = 1;
        a[2] = 2;
        FOR(i, 3, maxn - 1) {
            a[i] = (1LL * (i + 2) * fpow(2, i - 3)) % MOD;
        }
//        FOR(i, 1, 30) cout << i << ' ' << a[i] << endl;
    }
    void initF() {
        f[0] = 1;
        FOR(i, 1, maxn - 1) f[i] = (1LL * f[i - 1] * i) % MOD;
        FOR(i, 0, maxn - 1) {
            finv[i] = fpow(f[i], MOD - 2);
            inv[i] = fpow(i, MOD - 2);
        }
    }
    void initG() {
        g[1] = 0;
        FOR(i, 2, maxn - 1) {
            int k = i - 1;
            FOR(j, 1, i - 1) {
                g[i] = (g[i] + (1LL * g[j] * a[k]) % MOD) % MOD;
                k--;
            }
            g[i] = (g[i] + catalan(i - 2)) % MOD;
        }
    }
    void init(int _MOD) {
        MOD = _MOD;
        initA();
        initF();
        initG();
    }
    int calc(int n) {
        return (1LL * g[n] * fpow(catalan(n - 1), MOD - 2)) % MOD;
    }
} c1, c2;

int t, n;

int32_t main() {
//    freopen("EXPTREE.INP", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    c1.init(MOD1);
    c2.init(MOD2);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << c1.calc(n) << ' ' << c2.calc(n) << '\n';
    }
    return 0;
}
