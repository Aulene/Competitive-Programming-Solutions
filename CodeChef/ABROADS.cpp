#include <bits/stdc++.h>
#include <unordered_set>

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
#define N 100007

int pop[N];
int lk[N], sz[N], rd[N];
unordered_set <int> lks;
vi ansv;
vector < pair <int, int> > e;
vector < pair <int, pair <int, int> > > ops;
multiset <int> ansset;
vvi g(100007);

int find(int x)
{
	while(x != lk[x]) x = lk[x];
	return x;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	ansset.erase(sz[a]);
	ansset.erase(sz[b]);
	sz[a] += sz[b];
	lk[b] = a;

	ansset.insert(sz[a]);
	// lks.erase(b);
	// lks.insert(a);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, q, i, j, k, u, v, w, a, b, ans;
		char op;

		cin >> n >> m >> q;

		for(i = 1; i <= n; i++) cin >> pop[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				e.pb(mp(u, v));
			}

		for(i = 0; i < q; i++)
			{
				cin >> op;
				if(op == 'P')
					{
						cin >> u >> v;
						ops.pb(mp(1, mp(u, pop[u])));
						pop[u] = v;
					}
				else
					{
						cin >> u;
						rd[u - 1] = 1;
						ops.pb(mp(2, mp(u - 1, 0)));
					}
			}

		reverse(ops.begin(), ops.end());

		for(i = 1; i <= n; i++) lk[i] = i, lks.insert(i);
		for(i = 1; i <= n; i++) sz[i] = pop[i], ansset.insert(pop[i]);

		// cout << endl;
		// for(i = 1; i <= n; i++) cout << sz[i] << " "; cout << endl;
		// for(i = 0; i < m; i++) cout << rd[i] << " "; cout << endl;
		// cout << endl;

		for(i = 0; i < m; i++)
			if(!rd[i]) 
				{
					u = e[i].f, v = e[i].s;
					if(!same(u, v)) unite(u, v);
				}

		for(i = 0; i < ops.size(); i++)
			{
				u = ops[i].f, v = ops[i].s.f, w = ops[i].s.s;
				ans = *ansset.rbegin();

				// for(auto it = lks.begin(); it != lks.end(); it++)
				// 	{ ans = max(ans, sz[*it]); }

				// cout << endl << "POP = ";
				// for(j = 1; j <= n; j++) cout << pop[j] << " "; cout << endl;
				// cout << "LKS = ";
				// for(auto it = lks.begin(); it != lks.end(); it++) cout << *it << " "; cout << endl << ans << endl;

				ansv.pb(ans);

				if(u == 1) 
					{
						k = find(v);
						ansset.erase(sz[k]);
						sz[k] = sz[k] - pop[v] + w;
						ansset.insert(sz[k]);
						pop[v] = w; 
					}
				else
					{
						a = e[v].f, b = e[v].s;
						if(!same(a, b)) unite(a, b);
					}
			}

		reverse(ansv.begin(), ansv.end());
		for(i = 0; i < ansv.size(); i++) cout << ansv[i] << endl;

		return 0;
	}