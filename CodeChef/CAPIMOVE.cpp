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

vvi g(50007);
int a[50007];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, i, j, u, v;

		cin >> t;

		while(t--)
			{
				mx.clear();

				cin >> n;
				for(i = 1; i <= n; i++) cin >> a[i];

				for(i = 0; i < n - 1; i++) {
					cin >> u >> v;
					g[u].pb(v), g[v].pb(u);
				}
				
				for(i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());

			}

		return 0;
	}