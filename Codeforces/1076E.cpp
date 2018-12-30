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
#define mid (start + end) / 2

const int N = 300007;

vvi g(N);
vvpi vs(N);

int lazy[4 * N + 7], ans[N];
int n;

struct RSTree
{
	int val;
	RSTree *l, *r;

	int merge(int a, int b) { return a + b; }

	RSTree *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RSTree *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != 0)
				{
					val += lazy[level];

					if(start != end) {
						lazy[2 * level] += lazy[level];
						lazy[2 * level + 1] += lazy[level];
					}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					val += v;

					if(start != end) {
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

	int query(int lazy[], int start, int end, int a, int b, int level = 1)
		{
			if(lazy[level] != 0)
				{
					val += lazy[level];

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

void dfs(RSTree *root, int idx = 1, int dist = 0, int p = -1) {

	for(auto it : vs[idx])
		root = root -> update(lazy, 0, N - 1, dist, dist + it.f, it.s);

	ans[idx] = root -> query(lazy, 0, N - 1, dist, dist);

	for(auto it : g[idx])
		if(it != p) dfs(root, it, dist + 1, idx);

	for(auto it : vs[idx])
		root = root -> update(lazy, 0, N - 1, dist, dist + it.f, -it.s);
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
		
		int m, i, j, u, v, d, x;

		cin >> n;

		for(i = 1; i <= n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		cin >> m;

		while(m--) {
			cin >> v >> d >> x;
			vs[v].pb({d, x});
		}

		RSTree *root = new RSTree;
		root = root -> build(0, N - 1);

		dfs(root);

		for(i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;

		return 0;
	}