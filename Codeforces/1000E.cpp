#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > vs(100007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		
		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			vs[u].pb(v);
			vs[v].pb(u);
		}


		return 0;
	}