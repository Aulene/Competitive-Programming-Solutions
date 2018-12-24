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
#define vppi vector < ppi >
#define zp mp(0, 0)

const int N = 100007;

int sp[N], lk[N], sz[N]; 
int k, ans;

vppi vs;

int find(int idx) {
	while(idx != lk[idx]) idx = lk[idx];
	return idx;
}

bool same(int a, int b) { return find(a) == find(b); }

int unite(int a, int b, int w) {
	a = find(a), b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	sp[a] += sp[b];
	lk[b] = a;
	if(sp[a] == k) {
		ans = w;
		return 1;
	}
	return 0;
}

bool cmp(ppi a, ppi b) { return a.s < b.s; }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, w;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++) lk[i] = i, sz[i] = 1;

		for(i = 1; i <= k; i++) cin >> u, sp[u] = 1;

		for(i = 0; i < m; i++) {
			cin >> u >> v >> w;
			vs.pb({{u, v}, w});
		}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < m; i++) {
			u = vs[i].f.f, v = vs[i].f.s, w = vs[i].s;
			if(!same(u, v)) {
				if(unite(u, v, w)) break;
			}
		}

		for(i = 1; i <= k; i++) cout << ans << " "; cout << endl;

		return 0;
	}