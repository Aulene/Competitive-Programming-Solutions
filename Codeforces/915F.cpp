#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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
#define zp mp(0, 0)

const int N = 1000007;

int a[N], am[N], lk[N], sz[N];
int ansmax = 0, ansmin = 0;

vpi vs;

int find(int idx) {
	while(idx != lk[idx]) idx = lk[idx];
	return idx;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
	a = find(a), b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	am[a] = max(am[a], am[b]);
	ansmax += (sz[a] * sz[b]) * am[a];
	sz[a] += sz[b];
	lk[b] = a;
}

void unite2(int a, int b) {
	a = find(a), b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	am[a] = min(am[a], am[b]);
	ansmin += (sz[a] * sz[b]) * am[a];
	sz[a] += sz[b];
	lk[b] = a;
}

bool cmp(pi x, pi y) { return max(a[x.f], a[x.s]) < max(a[y.f], a[y.s]); }
bool cmp2(pi x, pi y) { return min(a[x.f], a[x.s]) > min(a[y.f], a[y.s]); }

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
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			lk[i] = i, sz[i] = 1, am[i] = a[i];
		}

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		sort(vs.begin(), vs.end(), cmp);

		for(auto it : vs) {
			// cout << it.f << " " << it.s << endl;
			u = it.f, v = it.s;
			if(!same(u, v)) unite(u, v);
		}
		for(i = 1; i <= n; i++)
			lk[i] = i, sz[i] = 1, am[i] = a[i];

		sort(vs.begin(), vs.end(), cmp2);

		for(auto it : vs) {
			// cout << it.f << " " << it.s << endl;
			u = it.f, v = it.s;
			if(!same(u, v)) unite2(u, v);
		}

		// cout << ansmax << " " << ansmin << endl;
		cout << ansmax - ansmin << endl;

		return 0;
	}