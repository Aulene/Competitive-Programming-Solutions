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

const int N = 200007;

vppi vs;

bool cmp(ppi a, ppi b) { return a.s < b.s; }

int lk[N], sz[N], sel[N];

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

void init() {
	for(int i = 0; i < N; i++) lk[i] = i, sz[i] = 1;
}

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
		
		init();

		int n, m, i, j, u, v, w, ans = 0, maxwt = 0, mst = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			 cin >> u >> v >> w;
			 vs.pb({{u, v}, w});
		}	

		sort(vs.begin(), vs.end(), cmp);

		// cout << endl;
		// for(auto it : vs) cout << it.f.f << " " << it.f.s << " " << it.s << endl; cout << endl;

		for(i = 0; i < m; i++) {

			for(j = i; j < m && vs[i].s == vs[j].s; j++) {
				u = vs[j].f.f, v = vs[j].f.s, w = vs[j].s;
				if(same(u, v)) sel[j] = 1;
			}

			for(j = i; j < m && vs[i].s == vs[j].s; j++) {
				if(!sel[j]) {
					u = vs[j].f.f, v = vs[j].f.s, w = vs[j].s;
					if(same(u, v)) ans++;
					else unite(u, v);
				}
			}

			i = j - 1;
		}

		cout << ans << endl;

		return 0;
	}