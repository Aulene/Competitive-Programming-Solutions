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

int a[N], lk[N], sz[N]; // lk initialized to i, sz initialized to 1

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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, w, mv = LLONG_MAX, mx, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) lk[i] = i, sz[i] = 1;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			if(mv > a[i]) {
				mv = a[i];
				mx = i;
			}
		}
	
		for(i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			vs.pb({{u, v}, w});
		}

		for(i = 1; i <= n; i++)
			if(i != mx) vs.pb({{mx, i}, mv + a[i]});

		sort(vs.begin(), vs.end(), cmp);

		for(auto it : vs) {
			if(!same(it.f.f, it.f.s)) {
				unite(it.f.f, it.f.s);
				ans += it.s;
			}
		}

		cout << ans << endl;


		return 0;
	}