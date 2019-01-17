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
#define ld long double

const int N = 100007;

vvi g(N);
vpi vs;

int a[N];

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

bool cmp(pi x, pi y) { return min(a[x.f], a[x.s]) > min(a[y.f], a[y.s]); }

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
		
		int n, m, i, j, k, l, u, v, w, sum = 0;
		int x, y;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			lk[i] = i, sz[i] = 1;
		}

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		sort(vs.begin(), vs.end(), cmp);

		for(auto it : vs) {
			// cout << it.f << " " << it.s << endl;
			u = it.f, v = it.s;
			w = min(a[u], a[v]);

			if(!same(u, v)) {	
				x = find(u), y = find(v);
				sum += w * sz[x] * sz[y];
				unite(u, v);
			}
		}

		sum *= 2;

		v = n * (n - 1);
		ld ans = (ld) sum / v;

		printf("%.16Lf\n", ans);

		return 0;
	}