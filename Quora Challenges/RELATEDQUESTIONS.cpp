#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
vector < vector <int> > vs(100007);

pair <int, int> dfs(int idx, int x, int p = -1)
{

}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			vs[u].pb(v);
			vs[v].pb(u);
		}

		return 0;
	}
