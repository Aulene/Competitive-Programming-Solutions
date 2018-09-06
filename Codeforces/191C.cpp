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

vvi g(100007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		return 0;
	}