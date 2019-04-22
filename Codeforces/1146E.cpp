#include <bits/stdc++.h>
 
using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REPD(i, n) for(int i = (n); i >= 0; i--)
#define FORD(i, a, b) for(int i = (a); i >= b; i--)
#define prArr(a, n) REP(i, n) cout << a[i] << " "; cout << endl;
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))
#define bin(a) bitset<32>(a)
#define endl '\n'
#define ld long double
#define int long long int
#define MOD 1000000007
#define p push
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define F first
#define S second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int >
#define vpi vector < pi >
#define vvpi vector < vector < pi > > 
#define vppi vector < pair < pi, int > > 
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
  Easy mistakes to spot before submitting!
  1. Check const int N (1e5, 2e5).
  2. Check easy cases (n = 1, 2).
  3. Overflows! You'll fuck this up when binary searching.
  4. LONG LONGS! Alternatively, remove the int long long int sometimes.
  5. Check if you're dividing by 0 somewhere.
  6. Memory allocations, sometimes the vector is N^2.
*/

const int N = 200200;
const int M = 100010;
 
struct SegmentTreeMax{
  int it[(N + 2) << 2];
  int lazy[(N + 2) << 3];
 
  #define mid ((l + r) >> 1)
 
  void Init(){
    memset(it, 0, sizeof it);
    memset(lazy, 0, sizeof lazy);
  }
 
  void push(int x){
    it[x] += lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
  }
 
  void update(int x, int l, int r, int u, int v, int val){
    if(v < u) return;
    push(x);
    if(l > v || r < u) return;
    if(l >= u && r <= v){
      lazy[x] += val;
      push(x);
      return;
    }
    update(2 * x, l, mid, u, v, val);
    update(2 * x + 1, mid + 1, r, u, v, val);
    it[x] = max(it[2 * x], it[2 * x + 1]);  
  }
 
  void modify(int x, int l, int r, int pos, int val){
    push(x);
    if(l > pos || r < pos) return;
    it[x] = max(it[x], val);
    if(l == r) return;
    modify(2 * x, l, mid, pos, val);
    modify(2 * x + 1, mid + 1, r, pos, val);
    it[x] = max(it[2 * x], it[2 * x + 1]);
  }
 
  int query(int x, int l, int r, int u, int v){
    push(x);
    if(u > v) return 0;
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return it[x];
    int ret = max(query(2 * x, l, mid, u, v), query(2 * x + 1, mid + 1, r, u, v));
    it[x] = max(it[2 * x], it[2 * x + 1]);
    return ret;
  }
}smt;
 
int n, q;
int a[N];
int ans[N];
int fmin2[N];
int fmax2[N];
vector < pair < pair < int, int >, int > > ask[N];
pair < int, int > queries[N];


signed main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // ifstream cin ("/Users/Aulene/Desktop/input.txt");
    // ofstream cout ("/Users/Aulene/Desktop/output.txt");

    // ifstream cin ("input.txt");
    // ofstream cout ("output.txt");
    
    // ifstream cin ("usaco.in");
    // ofstream cout ("usaco.out");
    
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
   
    for(int i = 1; i <= q; ++i) {
      char c; int x;
      cin >> c >> x;
      queries[i] = make_pair((c == '>'), x);
      smt.modify(1, 1, N, x + M, i);
    }
   
   
   
    for(int i = 1; i <= n; ++i) {
      int get = smt.query(1, 1, N, min(-a[i], a[i]) + M, max(-a[i], a[i]) + M);
      if(queries[get].first == 0) ans[i] = 1; /// 1 if greater one
      ask[get + 1].emplace_back(make_pair(min(-a[i], a[i]) + M - 1, 1), i);
      ask[get + 1].emplace_back(make_pair(max(-a[i], a[i]) + M + 1, 0), i);
    }
   
    for(int i = q; i >= 1; --i) {
      if(queries[i].first == 0) {
        for(int x = queries[i].second + M; x > 0; x &= x - 1) {
          fmax2[x] ^= 1;
        }
      }
      else{
        for(int x = queries[i].second + M; x < N; x += x & -x) {
          fmin2[x] ^= 1;
        }
      }
   
      for(auto &p : ask[i]) {
        auto r = p.first; 
        int idx = p.second;
   
        if(r.second) {
          for(int x = r.first; x; x &= x - 1) {
            ans[idx] ^= fmin2[x];
          }
        }
        else{
          for(int x = r.first; x < N; x += x & -x) {
            ans[idx] ^= fmax2[x];
          }
        }
      }
    }
   
    for(int i = 1; i <= n; ++i) {
      if(ans[i]) cout << max(a[i], -a[i]);
      else cout << min(a[i], -a[i]);
      cout << " ";
    }
  
    return 0;
  }

/*
  Snippet Guide - 
  1. Base Conversion - baseconv
  2. Binary Exponentiation (a ^ b % m) - powmod 
  3. Centroid Decomposition - centroid
  4. Code Jam Input - jam
  5. Disjoint Set Union - dsu
  6. Factorial Method - factorials
  7. Factorization O(SqrtN) - factors
  8. Greatest Common Divisor - gcd
  9. Line Template - line
  10. Matrix Exponentiation - matrix
  11. Merge Sort Tree - mstree
  12. Modular Inverse - modinv
  13. Point Template - point
  14. Range Segment Tree (w/ Lazy) - segtree
  15. Range Segment Tree (w/out Lazy) - rstree
  16. Sieve of Eratosthenes - sieve
  17. Topological Sort - toposort
*/
