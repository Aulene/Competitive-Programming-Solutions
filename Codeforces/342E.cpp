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
#define mid (start + end) / 2
#define zp mp(0, 0)

const int N = 100007;

vvi g(N);

int d[N], tin[N], tout[N];
int lazy[4 * N];
int t = 1;

void dfs(int idx, int p = 0) {
	d[idx] = d[p] + 1;
	tin[idx] = t++;
	for(auto it : g[idx])
		if(it != p) dfs(it, idx);
	tout[idx] = t++;
}

struct RangeSTreeLazy
{
	pi val;
	RangeSTreeLazy *l, *r;

	pi merge(pi a, pi b) { 
		pi ans;
		ans.f = max(a.f, b.f);
		ans.s = min(a.s, b.s);
		return ans;
	}

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end) val = mp(d[1], N);
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RangeSTreeLazy *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != 0)
				{
					val = merge(val, lazy[level]);

					if(start != end)
						{
							lazy[2 * level] = lazy[level];
							lazy[2 * level + 1] = lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {
				val = v;

				if(start != end) {
					lazy[2 * level] = v;
					lazy[2 * level + 1] = v;
				}			

				return this;
			}

	// 		l = l -> update(lazy, start, mid, a, b, v, 2 * level);
	// 		r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
	// 		val = merge(l -> val, r -> val);
	// 		return this;
	// 	}

	// int query(int lazy[], int start, int end, int a, int b, int level = 1)
	// 	{
	// 		if(lazy[level] != 0)
	// 			{
	// 				val = lazy[level];

	// 				if(start != end)
	// 					{
	// 						lazy[2 * level] = lazy[level];
	// 						lazy[2 * level + 1] = lazy[level];
	// 					}

	// 				lazy[level] = 0;
	// 			}

	// 		if(start > b || end < a)
	// 			return 0;
	// 		else if(start >= a && end <= b)
	// 			return val;
	// 		else
	// 			return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
	// 	}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs(1);

		cout << "DP[]: "; for(i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;
		cout << "T1[]: "; for(i = 1; i <= n; i++) cout << tin[i] << " "; cout << endl;
		cout << "T2[]: "; for(i = 1; i <= n; i++) cout << tout[i] << " "; cout << endl;

		RangeSTreeLazy *root = new RangeSTreeLazy;
		root = root -> build(1, t);

		// while(m--) {
		// 	cin >> u >> v;

		// 	if(u == 1) {

		// 	}
		// 	else {

		// 	}
		// }

		return 0;
	}