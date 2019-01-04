// -----------
// Bit Operations
// -----------

// Total number of set bits
u =  __builtin_popcount(n);

// Multiply by 2
n = n << 1;

// Divide by 2
n = n >> 1;

// Turn off rightmost set bit
n = n & (n - 1);

// Set ith bit
n = n | (1 << i);

// Unset ith bit
n = n & !(1 << i);

// Check if ith bit is set
u = n & (1 << i); // non-zero if set

// Find rightmost set bit
u = log2(n & -n) + 1;

// Find leftmost (most significant) set bit
u = (int)(log2l(n)) + 1;

// ----------
// STL HAX
// -----------

// Erase one element in a multiset mx
auto itr = mx.find(a[i]);
if(itr != mx.end())
    mx.erase(itr);

// Maximum element in a multiset mx
x = *mx.rbegin();
// -----------

// -----------
// Find all Cycles in a Graph
// -----------

vector <int> path;
vector < vector <int> > cycles;
int vis[N];
vvi g(N);

void dfs(int v) 
{
    path.push_back(v);
    vis[v] = 1;
    
    for(int i = 0; i < g[v].size(); i++)
	    {
	    	int u = g[v][i];

	    	if(vis[u] != 2) 
			    {
			        if(vis[u] == 1) 
				        {
				            cycles.emplace_back();

				            int id = path.size() - 1;
				            
				            while(path[id] != u)
				                cycles.back().push_back(path[id--]);

				            cycles.back().push_back(u);
				        } 
			        else
			            dfs(u);
			    }
    	}
    

    path.pop_back();
    vis[v] = 2;
}

// -----------
// Find all Strongly Connected Components (SCCs) in a Directed Graph
// -----------

int onStack[N], low[N], ids[N];
vector < vector <int> > g(N); 
vector < vector <int> > SCCs; // contains all found SCCs
vector <int> path;
stack <int> sx;
int id = 1;

void findSCC(int idx)
{
	/*
	// put next lines in main
	// memset(ids, -1, sizeof(ids));
	// for(i = 1; i <= n; i++)
	// 	if(ids[i] == -1) findSCC(i);
	*/
	
	sx.push(idx);
	onStack[idx] = 1;
	ids[idx] = low[idx] = id++;

	for(int i = 0; i < g[idx].size(); i++) 
		{
			int u = g[idx][i];

			if(ids[u] == -1)
				{
					findSCC(u);
					low[idx] = min(low[idx], low[u]);
				}
			else if(onStack[u]) 
				low[idx] = min(low[idx], ids[u]);
		}

	if(ids[idx] == low[idx]) 
		{
			vector <int> path;

			while(sx.top() != idx) 
				{
					int u = sx.top();
					sx.pop();
					onStack[u] = 0;
					path.pb(u);
				}

			int u = sx.top();
			sx.pop();
			onStack[u] = 0;
			path.pb(u);

			SCCs.emplace_back();
			SCCs.back() = path;
		}
}

// two intersecting segments
bool intersect(int x1, int y1, int x2, int y2)
{
	if(x2 <= x1 && x1 <= y2) return 0;
	if(x2 <= y1 && y1 <= y2) return 0;
	if(x1 <= x2 && x2 <= y1) return 0;
	if(x1 <= y2 && y2 <= y1) return 0;
	return 1;	
}

bool intersect(pair <int, int> p1, pair <int, int> p2)
{
	if(p2.f <= p1.f && p1.f <= p2.s) return 0;
	if(p2.f <= p1.s && p1.s <= p2.s) return 0;
	if(p1.f <= p2.f && p2.f <= p1.s) return 0;
	if(p1.f <= p2.s && p2.s <= p1.s) return 0;
	return 1;	
}

// Sieve of Eratosthenes

bool prime[N];
vi vs;

void sieve()
{
	for(int i = 2; i < N; i++) prime[i] = 1;

	for(int i = 2; i < N; i++) {
		if(prime[i]) {
			vs.pb(i);
			for(int j = i * i; j < N; j += i) prime[j] = 0;
		}
	}
}

// Ranged Lazy Segment Tree
struct RangeSTreeLazy
{
	int val;
	RangeSTreeLazy *l, *r;

	int merge(int a, int b) { return a + b; }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RangeSTreeLazy *update(int lazy[], int start, int end, int a, int b, int v, int level)	
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					val += (end - start + 1) * v;

					if(start != end)
						{
							lazy[2 * level] += v;
							lazy[2 * level + 1] += v;
						}			

					return this;
				}

			l = l -> update(lazy, start, mid, a, b, v, 2 * level);
			r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int lazy[], int start, int end, int a, int b, int level)
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
		}
};

// ------------------
// POWMOD - Computing a^b % m
// ------------------
int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}
// ------------------
// Mod Inverse
// ------------------
int inv(int a, int m) { return a < 2 ? a : ((1 - m * 1ll * inv(m % a, a)) / a % m + m) % m; }

// ------------------
// Mod Mult (a * b) % m
// ------------------
inline int modMul(const int x, const int y) {
	if (x > (1<<30) && y > (1 << 30))
		return ((x >> 30) * ((y << 30) % mod) + y * (x & ((1 << 30) - 1))) % mod;
	int z = x * y;
	if (z >= mod)
		z %= mod;
	return z;
}

// ------------------
// Factors of a Number O(Sqrt(N))
// ------------------

vi factors(int n) {
	vi fax;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	return fax;
}

// Miller-Rabin Primality Test
int miller_rabin(int n) {
	if(n == 1) return 0;

	int b = 2;
	for(int g; (g = gcd(n, b)) != 1; ++b)
		if(n > g) return 0;
	int p = 0, q = n - 1;
	while((q & 1) == 0)
		++p,  q >>= 1;
	int rem = powmod(b, q, n);
	if(rem == 1 || rem == n - 1) return 1;
	for(int i = 1; i < p; ++i) {
		rem = (rem * 1ll * rem) % n;
		if(rem == n - 1) return 1;
	}
	return 0;
}

// ------------------
// Euclid GCD
// ------------------
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

// Minimum Sparse Table, 1-Indexed

int mint[300007][27];

void preprocessMin(int n) {

	for(int i = 1; i <= n; i++)
		table[i][0] = a[i];

	for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            int k = i + (1 << (j - 1));
            table[i][j] = min(table[i][j - 1], table[k][j - 1]);
    }
}

int query(int x, int y) {
	int len = y - x + 1;
	int k = log2(len);
	return min(table[x][k], table[y - (1 << k) + 1][k]);
}

// ------------------
// Disjoint Set Union
// ------------------

int lk[N], sz[N]; // lk initialized to i, sz initialized to 1

int find(int idx) {
	while(idx != lk[idx]) idx = lk[idx];
	return idx;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
	a = find(a), b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	lk[b] = a;
}

// ------------------
// Matrix Exponentiation
// ------------------

const int K = 4;

vvi mul(vvi a, vvi b) {
    vvi ans(K + 1, vi(K + 1));

    for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++)
            for(int k = 1; k <= K; k++)
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][k]) % mod;
    return ans;
}

vvi pow(vvi a, int n) {

    if(n == 1) return a;
    if(n % 2)
        return mul(a, pow(a, n - 1));
    vvi b = pow(a, n / 2);
    return mul(b, b);
}

// ------------------
// Fast Fourier Transform (FFT)
// ------------------

typedef complex<ld> cld;
const double pi = acos(-1.0);
const int N = 500500;

void fft(vector<cld> &a, bool invert){
	int n = a.size();

	// bit reverse copy procedure
	for(int i = 1, j = 0; i < n; i++){
		int bit = n / 2;
		for(; j >= bit; bit /= 2){
			j-=bit;
		}
		j+=bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(int len = 2; len <= n; len *= 2){
		double angle = 2 * pi / len * (invert ? -1 : 1);
		cld wnrt = cld(cos(angle), sin(angle));
		for(int i = 0; i < n; i+=len){
			cld w(1);
			for(int j = 0; j < len / 2; j++){
				cld u = a[i + j], v = w * a[i + j + len / 2];
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wnrt;
			}
		}
	}

	if(invert){
		for(int i = 0; i < n; i++) a[i] /= (ld)n;
	}

}

vector<int> multiply(vector<int> &a, vector<int> &b){
	vector<cld> fa(a.begin(), a.end()), fb(a.begin(), a.end());
	int n = 1;
	while(n < 2 * max(a.size(), b.size())) n*=2;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for(int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		c[i] = (int)round(fa[i].real());
	}
	return c;
}

int main(){
	vector<int> a = {1,1,2,2};
	vector<int> b = {1,1};
	vector<int> c = multiply(a, a);
	for(int u : c ) cout << u << " ";
	cout << endl;
	return 0;
}