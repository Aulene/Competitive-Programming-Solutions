#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ld long double
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)


const int N = 1e5;

vector<int> tree[N];
vector<int> cent[N]; // centroid tree
bool centroidMarked[N];
int subtree_size[N];

void dfs(int u, int p) {
	subtree_size[u] = 1;
	for(auto v : tree[u]){
		if(v != p && !centroidMarked[v]){
			dfs(v, u);
			subtree_size[u] += subtree_size[v];
		}
	}
}

int getCentroid(int u, int p, int n){
	bool is_centroid = true;
	int heaviest_child = -1;

	for(auto v : tree[u]){
		if(v != p && !centroidMarked[v]){
			if(subtree_size[v] > n / 2)
				is_centroid = false;
			if(heaviest_child == -1 || subtree_size[v] > subtree_size[heaviest_child])
				heaviest_child = v;
		}
	}
	if(is_centroid && n - subtree_size[u] <= n / 2){
		return u;
	}
	return getCentroid(heaviest_child, u, n);
}

int getCentroid(int u){
	dfs(u, -1);
	int centroid = getCentroid(u, -1, subtree_size[u]);
	centroidMarked[centroid] = true;
	return centroid;
}

int centroidDecomp(int root){
	int centroid = getCentroid(root);
	for(auto v : tree[centroid]){
		if(!centroidMarked[v]){
			int centroidsub = centroidDecomp(v);
			cent[centroid].pb(centroidsub);
			cent[centroidsub].pb(centroid);
		}
	}
	return centroid;
}

void addEdge(int a, int b) {
	tree[a].pb(b);
	tree[b].pb(a);
}

/*
	// in main

	int root = centroidDecomp(1);
	for(auto x : cent[c]){
		cout << x << endl;
	}
*/
const int N = 100007;

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

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}

int inv(int a, int m) { return a < 2 ? a : ((1 - m * 1ll * inv(m % a, a)) / a % m + m) % m; }

int fact[N], vis[N];

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
			
		int n, m, i, j, u, v, w, ans = 0, sum = 0;

		cin >> n >> m;

		ans = powmod(n, m, mod)

		for(i = 1; i <= n; i++) lk[i] = i, sz[i] = 1;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v >> w;
			if(w == 0 && !same(u, v)) 
				unite(u, v);
		}

		for(i = 1; i <= n; i++) {
			int p = find(i);

			if(!vis[p]) {
				int cur = powmod(sz[p], m, mod);
				ans = (ans - cur + mod) % mod; 
				vis[p] = 1;
			}
		}

		cout << ans << endl;
		

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
	9. Matrix Exponentiation - matrix
	10. Merge Sort Tree - mstree
	11. Modular Inverse - modinv
	12. Range Segment Tree (w/ Lazy) - segtree
	13. Range Segment Tree (w/out Lazy) - rstree
	14. Sieve of Eratosthenes - sieve
*/
